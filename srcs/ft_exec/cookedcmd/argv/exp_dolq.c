/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_dolq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 21:53:18 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	dolq2(t_wexpinf *weinf, char *src, t_cmdarg *arg, t_shdata *data)
{
	char		*next_d;
	t_chrmsk	*delim;
	t_bool		esc_c;
	char		c;

	(void)data;
	esc_c = FALSE;
	delim = get_delim_msk(WEXP_DOQMSK);
	src++;
	while ((next_d = chrmsk_getnext_match(src, delim)))
	{
		if (esc_c == FALSE && copy_str2arg(arg, src, next_d - src) == FAILURE)
			return (ST_FAILURE);
		if (*next_d == '\'')
			break ;
		if (!(c = parse_backslash_total(next_d, &src)))
			esc_c = TRUE;
		if (esc_c == FALSE && copy_chr2arg(arg, c) == FAILURE)
			return (ST_FAILURE);
	}
	if (!next_d)
		return (ST_FAILURE);
	weinf->src = next_d + 1;
	return (ST_CONTINUE);
}

static int	dolq1(t_wexpinf *weinf, char *src, t_cmdarg *arg, t_shdata *data)
{
	char		*next_d;
	t_chrmsk	*delim;
	t_bool		esc_c;
	char		c;

	(void)data;
	esc_c = FALSE;
	delim = get_delim_msk(WEXP_DODQMSK);
	src++;
	while ((next_d = chrmsk_getnext_match(src, delim)))
	{
		if (esc_c == FALSE && copy_str2arg(arg, src, next_d - src) == FAILURE)
			return (ST_FAILURE);
		if (*next_d == '\'' || *next_d == '"')
			break ;
		if (!(c = parse_backslash_total(next_d, &src)))
			esc_c = TRUE;
		if (esc_c == FALSE && copy_chr2arg(arg, c) == FAILURE)
			return (ST_FAILURE);
	}
	if (!next_d || *next_d == '"')
		return (ST_FAILURE);
	weinf->src = next_d + 1;
	return (ST_CONTINUE);
}

int			exp_dolq(t_wexpinf *weinf, char *src, t_cmdarg *arg, t_shdata *data)
{
	size_t	arg_save;

	if (weinf->state & SET_DQUMODE)
	{
		arg_save = arg->size;
		if (dolq1(weinf, src, arg, data) == ST_FAILURE)
		{
			if (arg->size == _POSIX_ARG_MAX)
				return (ST_FAILURE);
			arg->size = arg_save;
			if (copy_str2arg(arg, src - 1, 2) == FAILURE)
				return (ST_FAILURE);
			weinf->src = src + 1;
		}
		return (ST_CONTINUE);
	}
	return (dolq2(weinf, src, arg, data));
}
