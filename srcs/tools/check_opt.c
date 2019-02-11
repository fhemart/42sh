/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:40:44 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 14:05:29 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

static int	std_optaction(t_optdata *opt_data, t_checkopt_inf *info)
{
	int		shift;
	char	c;

	if ((c = opt_data->optret) == '?')
		return (ST_FAILURE);
	shift = ft_chr2index(info->msk, c);
	info->flags |= (1 << shift);
	return (ST_CONTINUE);
}

void		init_coptinf(t_checkopt_inf *dst, char *msk, void *custom, \
						int (*optaction)(t_optdata*, t_checkopt_inf*))
{
	if (!(dst->optaction = optaction))
		dst->optaction = std_optaction;
	dst->custom = custom;
	dst->msk = msk;
	dst->flags = 0;
}

int			check_opt(int argc, char **args, int signs, t_checkopt_inf *optinf)
{
	t_optdata	od;
	char		*msk;
	int			action_result;

	init_optdata(&od, signs);
	msk = optinf->msk;
	while ((od.optret = ft_getopt(&od, argc, args, msk)) != -1
	&& (action_result = optinf->optaction(&od, optinf)) == ST_CONTINUE)
		;
	if (od.optret == -1 || action_result == ST_SUCCESS)
		return (od.optind);
	return (-1);
}
