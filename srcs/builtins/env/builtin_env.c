/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 20:02:01 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static void			restore_cmd(t_cookedcmd *cmd, t_shdata *data, \
								t_envsave *save)
{
	cmd->argc = save->old_argc;
	cmd->argv = save->old_argv;
	ft_hashtable_destroy(&data->books->hashtable, hashtable_destroy_content);
	data->books->hashtable = save->ht;
	data->env->var = save->vklist;
	data->info.home = save->home;
}

static void			update_cmd_args(t_cookedcmd *cmd, int count)
{
	cmd->argv += 1 + count;
	cmd->argc -= count + 1;
}

static int			display_help(t_envsave *save)
{
	ft_hashtable_destroy(&save->ht, hashtable_destroy_content);
	ft_putstr(ENV_HELP);
	return (EXIT_SUCCESS);
}

static void			envsave_start(t_envsave *save, t_shdata *data, \
									t_cookedcmd *cmd)
{
	save->old_argv = cmd->argv;
	save->old_argc = cmd->argc;
	save->ht = data->books->hashtable;
	save->vklist = data->env->var;
	save->home = data->info.home;
	ft_hashtable_new(&data->books->hashtable);
}

int					builtin_env(t_cookedcmd *cmd, t_shdata *data)
{
	t_checkopt_inf	coptinf;
	t_sh_evar		*var;
	t_envsave		save;
	int				ret;

	g_last_signal = 0;
	signal(SIGPIPE, pipe_sig);
	envsave_start(&save, data, cmd);
	if (builtin_need_help(save.old_argv + 1) == TRUE)
		return (display_help(&save));
	init_coptinf(&coptinf, "i0", NULL, env_optaction);
	ret = check_opt(save.old_argc - 1, save.old_argv + 1, \
					GETOPT_SNEG, &coptinf);
	update_cmd_args(cmd, ret);
	ret = ENV_PRINT;
	var = env_parse_argv(cmd, coptinf.flags, &ret);
	if (ret == ENV_PRINT && env_print(cmd->env_var, \
						(coptinf.flags & (1 << 1) ? '\0' : '\n')) == FAILURE)
		ret = ft_write_error(SHELL_NAME": env: ");
	else if (ret == ENV_EXEC)
		ret = exec_env(&save, cmd, coptinf.flags, data);
	restore_cmd(cmd, data, &save);
	sh_evar_recdel(var);
	return (ret);
}
