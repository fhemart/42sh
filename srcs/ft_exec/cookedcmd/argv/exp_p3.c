/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_p3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/02 15:55:16 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			exp_equal(t_wexpinf *weinf, char *next_d, t_shdata *data)
{
	t_cmdarg	*arg;
	char		*src;

	arg = weinf->argline;
	src = weinf->src;
	if (copy_str2arg(arg, src, ++next_d - src) == FAILURE)
		return (ST_FAILURE);
	src = next_d;
	if (is_valid_varname2(weinf->src_orig, (size_t)(next_d - weinf->src_orig)))
	{
		if (expand_tilde(arg, &src, &data->info) == FAILURE)
			return (ST_FAILURE);
	}
	weinf->src = src;
	weinf->state = 1;
	return (ST_CONTINUE);
}

static int	exp_bsdqu_nlcase(t_bool *skip, char **next_d, t_cmdarg *arg, \
							char *src)
{
	char	*nextd;

	nextd = *next_d;
	if (nextd[1] == '\n')
	{
		if (copy_str2arg(arg, src, nextd++ - src) == FAILURE)
		{
			*next_d = nextd;
			return (ST_FAILURE);
		}
	}
	else if (copy_str2arg(arg, src, (nextd + 1) - src) == FAILURE)
	{
		*next_d = nextd;
		return (ST_FAILURE);
	}
	*next_d = nextd;
	*skip = TRUE;
	return (ST_CONTINUE);
}

static int	exp_bsdqu(t_wexpinf *weinf, char *next_d, t_cmdarg *arg, char *src)
{
	t_chrmsk	*dqumsk;
	t_bool		skip;

	dqumsk = get_delim_msk(WEXP_DQUBSMSK);
	if (char_match_pattern(next_d[1], dqumsk))
	{
		if (copy_str2arg(arg, src, next_d - src) == FAILURE)
			return (ST_FAILURE);
		skip = FALSE;
	}
	else if (exp_bsdqu_nlcase(&skip, &next_d, arg, src) == ST_FAILURE)
		return (ST_FAILURE);
	src = ++next_d;
	if (skip == FALSE && copy_chr2arg(arg, *(src++)) == FAILURE)
		return (ST_FAILURE);
	weinf->src = src;
	return (ST_CONTINUE);
}

static void	restore_weinf(t_wexpinf *weinf)
{
	ft_strdel(&weinf->src_cmdsubst);
	weinf->src = weinf->save_src;
	weinf->save_src = NULL;
	weinf->state = weinf->save_state;
}

int			exp_bs(t_wexpinf *weinf, char *next_d, t_shdata *data)
{
	t_cmdarg	*arg;
	char		*src;

	(void)data;
	arg = weinf->argline;
	src = weinf->src;
	if (weinf->state & SET_DQUMODE)
		return (exp_bsdqu(weinf, next_d, arg, src));
	if (copy_str2arg(arg, src, next_d - src) == FAILURE)
		return (ST_FAILURE);
	if (*(src = ++next_d) == '\n')
		weinf->src = ++src;
	else if (*src)
	{
		if (copy_chr2arg(arg, *src) == FAILURE)
			return (ST_FAILURE);
		weinf->src = src + 1;
	}
	else if (weinf->src_cmdsubst)
		restore_weinf(weinf);
	else
		return (ST_SUCCESS);
	return (ST_CONTINUE);
}
