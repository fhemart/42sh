/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cookedcmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/07 02:44:16 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	ft_exec_builtin(t_cookedcmd *cmd, t_shdata *shdata)
{
	int		ret;

	if (compress_iocontent(&cmd->cookedio, cmd->ioctt) == FAILURE)
		ret = 2;
	else
		ret = shdata->builtins[cmd->type].f(cmd, shdata);
	reset_cookedio(&cmd->cookedio);
	return (ret);
}

static int	ft_exec_file(t_cookedcmd *cmd, t_shdata *shdata)
{
	pid_t		pid;
	int			exec_ret;
	int			c_ret;
	char		**env;

	if ((pid = fork()) == -1)
		return (p_eagain(SHELL_NAME ": fork: "));
	else if (pid == 0)
	{
		close_saved_stdio(shdata);
		env = create_tmpenv(cmd);
		if ((c_ret = compress_iocontent(&cmd->cookedio, cmd->ioctt)) != FAILURE)
			execve(cmd->name, cmd->argv, env);
		ft_arstrdel(&env);
		reset_cookedio(&cmd->cookedio);
		if (c_ret == SUCCESS)
			ft_exec_shellfile(cmd, shdata);
		exit_shell(cmd, shdata, EXIT_FAILURE);
	}
	waitpid(pid, &exec_ret, 0);
	return (parse_exec_ret(exec_ret, cmd, pid));
}

int			ft_exec_cookedcmd(t_cookedcmd *cmd, t_shdata *shdata)
{
	static int	(*const exectype[2])(t_cookedcmd*, t_shdata*) = {\
									ft_exec_builtin, ft_exec_file};

	return (exectype[(cmd->type >> 8)](cmd, shdata));
}
