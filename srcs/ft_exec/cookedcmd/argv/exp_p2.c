/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_p2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 16:30:51 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		exp_dshpid(t_wexpinf *weinf, char *src, t_cmdarg *arg, t_shdata *data)
{
	if (copy_int2arg(arg, data->pid) == FAILURE)
		return (ST_FAILURE);
	weinf->src = ++src;
	return (ST_CONTINUE);
}

int		exp_qu(t_wexpinf *weinf, char *next_d, t_shdata *data)
{
	t_cmdarg	*arg;
	char		*src;

	(void)data;
	arg = weinf->argline;
	src = weinf->src;
	if (copy_str2arg(arg, src, next_d - src) == FAILURE)
		return (ST_FAILURE);
	src = next_d + 1;
	if (!(next_d = ft_strchr(src, '\''))
	|| copy_str2arg(arg, src, next_d - src) == FAILURE)
		return (ST_FAILURE);
	weinf->src = next_d + 1;
	return (ST_CONTINUE);
}

int		exp_dqu(t_wexpinf *weinf, char *next_d, t_shdata *data)
{
	static int	oldmode;
	t_cmdarg	*arg;
	char		*src;

	(void)data;
	arg = weinf->argline;
	src = weinf->src;
	if (copy_str2arg(arg, src, next_d - src) == FAILURE)
		return (ST_FAILURE);
	weinf->src = next_d + 1;
	if (weinf->state & SET_DQUMODE)
		weinf->state = oldmode;
	else
	{
		oldmode = weinf->state;
		weinf->state = SET_DQUMODE;
	}
	return (ST_CONTINUE);
}

int		exp_end(t_wexpinf *weinf, char *next_d, t_shdata *data)
{
	t_cmdarg	*arg;

	(void)next_d;
	(void)data;
	arg = weinf->argline;
	if (copy_str2arg(arg, weinf->src, ft_strlen(weinf->src)) == FAILURE)
		return (ST_FAILURE);
	if (weinf->src_cmdsubst)
	{
		ft_strdel(&weinf->src_cmdsubst);
		weinf->src = weinf->save_src;
		weinf->state = weinf->save_state;
		return (ST_CONTINUE);
	}
	arg->buff[arg->size] = '\0';
	if (!arg->size && weinf->parsed_subst == 1)
		arg->size = -1;
	return (ST_SUCCESS);
}

int		exp_dnone(t_wexpinf *weinf, char *src, t_cmdarg *arg, t_shdata *data)
{
	(void)data;
	if (copy_chr2arg(arg, '$') == FAILURE)
		return (ST_FAILURE);
	weinf->src = src;
	return (ST_CONTINUE);
}
