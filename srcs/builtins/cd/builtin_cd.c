/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 16:44:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "builtins_private.h"

static int	cd_optaction(t_optdata *opt_data, t_checkopt_inf *info)
{
	int		shift;
	char	c;

	if ((c = opt_data->optret) == '?')
	{
		if (opt_data->optopt != '\0')
		{
			print_bad_opt("cd", opt_data->optopt);
			ft_putstr_fd(CD_USAGE"\n", 2);
			return (ST_FAILURE);
		}
		info->flags |= (1 << 2);
	}
	else
	{
		shift = ft_chr2index(info->msk, c);
		info->flags = (info->flags & (1 << 2)) + (shift + 1);
	}
	return (ST_CONTINUE);
}

int			builtin_cd(t_cookedcmd *cmd, t_shdata *shdata)
{
	t_checkopt_inf	coptinf;
	char			**args;
	char			*arg;
	int				optret;

	init_coptinf(&coptinf, "LP", NULL, cd_optaction);
	args = cmd->argv + 1;
	if ((optret = check_opt(cmd->argc - 1, args, GETOPT_SNEG, &coptinf)) == -1)
		return (EXIT_FAILURE);
	arg = args[optret];
	if (!(coptinf.flags & ~(1 << 2)))
		coptinf.flags |= (1 << (shdata->opts & SET_PHSXLNK ? 1 : 0));
	if (coptinf.flags & (1 << 2))
		return (cd_go_oldpwd(coptinf.flags, shdata));
	else if (!arg)
		return (cd_go_home(coptinf.flags, shdata));
	return (find_path(coptinf.flags, arg, shdata));
}
