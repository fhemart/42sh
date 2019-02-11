/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_optaction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:54:37 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			flag2index(int flag)
{
	int		i;

	i = -1;
	while (++i < 4 && !(flag & (0xff)))
		flag >>= 8;
	return (flag - 1);
}

static int	flg_err(t_checkopt_inf *info, char c, int err)
{
	ft_putstr_fd(SHELL_NAME ": history: ", 2);
	if (err == 2 && (info->flags & (0xff0000)))
		ft_putendl_fd(HIST_EARNW, 2);
	else
	{
		ft_putchar_fd('-', 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(HIST_ECNFLCT, 2);
		ft_putchar_fd(info->msk[flag2index(info->flags)], 2);
		ft_putchar_fd('\n', 2);
	}
	ft_putstr_fd(HIST_USAGE"\n", 2);
	return (ST_FAILURE);
}

static int	get_cmp(int shift)
{
	if (shift == 0 || shift == 1)
		return (shift);
	return ((shift < 6) ? 2 : 3);
}

static int	update_flags(t_optdata *opt_data, t_checkopt_inf *info, char c)
{
	int			shift;
	int			flags;
	int			cmp;

	shift = ft_chr2index(info->msk, c);
	flags = info->flags;
	cmp = get_cmp(shift);
	if (flags & ~(0xff << (cmp * 8)) || (cmp == 2 && flags & 0xff0000))
		return (flg_err(info, c, cmp));
	info->flags = (shift + 1) << (cmp * 8);
	if (cmp != 1)
		return (ST_CONTINUE);
	info->custom = opt_data->optarg;
	return (ST_SUCCESS);
}

int			hist_optaction(t_optdata *opt_data, t_checkopt_inf *info)
{
	char	c;

	if ((c = opt_data->optret) == '?')
	{
		if (opt_data->optopt == '\0')
			return (ST_SUCCESS);
		print_bad_opt("history", opt_data->optopt);
		ft_putstr_fd(HIST_USAGE"\n", 2);
		return (ST_FAILURE);
	}
	return (update_flags(opt_data, info, c));
}
