/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 16:00:34 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			exec_subshell(t_subshell *subshell, t_shdata *shdata)
{
	t_cookedio	cookedio;
	int			exec_ret;
	pid_t		pid;

	exec_ret = 0;
	if ((pid = fork()) == -1)
		return (-p_eagain(SHELL_NAME ": fork: "));
	else if (pid == 0)
	{
		ft_bzero(&cookedio, sizeof(cookedio));
		init_stdiotable(cookedio.stdio);
		if (compress_iocontent(&cookedio, subshell->iocontent) != FAILURE)
			exec_ret = ft_exec_inputlist(&subshell->ilist, shdata);
		else
			exec_ret = 1;
		reset_cookedio(&cookedio);
		exit_shell(NULL, shdata, exec_ret);
	}
	waitpid(pid, &exec_ret, 0);
	return (WEXITSTATUS(exec_ret));
}

int			pl_exec_builtin(t_cookedcmd *cmd, t_shdata *shdata)
{
	int			exec_ret;

	exec_ret = 0;
	close(STDIN_FILENO);
	if (compress_iocontent(&cmd->cookedio, cmd->ioctt) != FAILURE)
		exec_ret = shdata->builtins[cmd->type].f(cmd, shdata);
	else
		exec_ret = 2;
	reset_cookedio(&cmd->cookedio);
	return (exec_ret);
}

int			pl_exec_file(t_cookedcmd *cmd, t_shdata *shdata)
{
	char	**env;

	(void)shdata;
	env = create_tmpenv(cmd);
	if (compress_iocontent(&cmd->cookedio, cmd->ioctt) != FAILURE)
		execve(cmd->name, cmd->argv, env);
	reset_cookedio(&cmd->cookedio);
	ft_arstrdel(&env);
	return (EXIT_FAILURE);
}

int			pl_exec_cookedcmd(t_cookedcmd *cmd, t_shdata *shdata)
{
	static int	(*const exectype[2])(t_cookedcmd*, t_shdata*) = {\
							pl_exec_builtin, pl_exec_file};
	int			ret_val;

	ret_val = exectype[(cmd->type >> 8)](cmd, shdata);
	return (ret_val);
}

int			pl_exec_cmd(t_command *cmd_raw, t_shdata *shdata)
{
	t_cookedcmd		*cmd;
	int				exec_ret;

	close_saved_stdio(shdata);
	if ((cmd = cookedcmd_new(cmd_raw, shdata)))
		exec_ret = pl_exec_cookedcmd(cmd, shdata);
	else
		exec_ret = shdata->last_retval;
	exit_shell(cmd, shdata, exec_ret);
	return (exec_ret);
}
