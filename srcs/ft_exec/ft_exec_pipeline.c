/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/07 02:44:16 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static inline void	launch_pipe(int *pfd, t_command *pipeline, t_shdata *shdata)
{
	call_dup2(pfd[0], STDIN_FILENO);
	close(pfd[1]);
	if (pipeline->type == SIMPLE_CMD)
		pl_exec_cmd(pipeline, shdata);
	else if (pipeline->type == SUBSHELL_CMD)
		shdata->last_retval = exec_subshell((t_subshell*)pipeline, shdata);
}

static inline void	launch_next_pipe(int *pfd, t_command *pipel, t_shdata *data)
{
	data->is_fork |= IS_SUBSHELL;
	call_dup2(pfd[1], STDOUT_FILENO);
	close(pfd[0]);
	exec_piped_cmd(pipel, data);
	exit_shell(NULL, data, data->last_retval);
}

static int			exec_single_command(t_command *cmd_raw, t_shdata *shdata)
{
	int			exec_ret;

	exec_ret = 0;
	if (cmd_raw->type == SIMPLE_CMD)
		exec_ret = ft_exec_cmd(cmd_raw, shdata);
	else if (cmd_raw->type == SUBSHELL_CMD)
		exec_ret = exec_subshell((t_subshell*)cmd_raw, shdata);
	shdata->last_retval = exec_ret;
	return (exec_ret);
}

int					exec_piped_cmd(t_command *pipeline, t_shdata *shdata)
{
	int			exec_ret;
	int			pfd[2];
	pid_t		pid[2];

	if (pipe(pfd) == -1)
		return (EXIT_FAILURE);
	if ((pid[0] = fork()) == 0)
		launch_pipe(pfd, pipeline, shdata);
	if (pipeline->next && (pid[1] = fork()) == 0)
		launch_next_pipe(pfd, pipeline->next, shdata);
	close(pfd[1]);
	close(pfd[0]);
	waitpid(pid[0], &exec_ret, 0);
	if (!(shdata->is_fork & IS_SUBSHELL))
		shdata->last_retval = WEXITSTATUS(exec_ret);
	waitpid(-1, NULL, 0);
	return (exec_ret);
}

int					ft_exec_pipeline(t_command *pipeline, t_shdata *shdata)
{
	int			exec_ret;

	save_stdio(shdata->save_stdio);
	if (!pipeline->next)
		exec_ret = exec_single_command(pipeline, shdata);
	else
		exec_ret = exec_piped_cmd(pipeline, shdata);
	restore_stdio(shdata->save_stdio);
	close_saved_stdio(shdata);
	return (exec_ret);
}
