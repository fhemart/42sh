/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 18:11:06 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static int		pwd_optaction(t_optdata *opt_data, t_checkopt_inf *info)
{
	int		shift;
	char	c;

	if ((c = opt_data->optret) == '?')
	{
		print_bad_opt("pwd", opt_data->optopt);
		ft_putstr_fd(PWD_USAGE"\n", 2);
		return (ST_FAILURE);
	}
	shift = ft_chr2index(info->msk, c);
	info->flags = shift + 1;
	return (ST_CONTINUE);
}

static int		print_ph_pwd(void)
{
	char		cwd[_POSIX_PATH_MAX];

	if (getcwd(cwd, _POSIX_PATH_MAX - 1) == NULL)
	{
		p_ename2long(SHELL_NAME": pwd: ");
		return (EXIT_FAILURE);
	}
	else if (ft_putendl(cwd) == FAILURE)
		return (ft_write_error(SHELL_NAME": pwd: "));
	return (EXIT_SUCCESS);
}

static int		print_ln_pwd(t_shinfo *shinf)
{
	char	*cwd;

	if (!(cwd = shinf->pwd))
		return (print_ph_pwd());
	else if (ft_putendl(cwd) == FAILURE)
		return (ft_write_error(SHELL_NAME": pwd: "));
	return (EXIT_SUCCESS);
}

int				builtin_pwd(t_cookedcmd *cmd, t_shdata *shdata)
{
	t_checkopt_inf	coptinf;
	char			**args;
	int				optret;

	g_last_signal = 0;
	signal(SIGPIPE, pipe_sig);
	init_coptinf(&coptinf, "LP", NULL, pwd_optaction);
	args = cmd->argv + 1;
	if ((optret = check_opt(cmd->argc - 1, args, GETOPT_SNEG, &coptinf)) == -1)
		return (EXIT_FAILURE);
	if (coptinf.flags == 2
	|| (shdata->opts & SET_PHSXLNK && coptinf.flags != 1))
		return (print_ph_pwd());
	return (print_ln_pwd(&shdata->info));
}
