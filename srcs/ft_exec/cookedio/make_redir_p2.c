/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redir_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:59:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/17 14:36:57 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int		iof_dgreat(int fd_left, char *str, t_cookedio *cookedio)
{
	int	fd_right;

	if ((fd_right = open(str, O_WRONLY | O_CREAT | O_APPEND, 0664)) == -1)
		return (open_error(str, O_WRONLY | O_CREAT | O_APPEND));
	if (call_dup2(fd_right, fd_left) == FAILURE)
		return (FAILURE);
	update_fdlist(&cookedio->openedfd, fd_right, fd_left);
	update_stdtable(cookedio->stdio, fd_right, fd_left);
	cookedio->modified = TRUE;
	return (SUCCESS);
}

int		iof_heredoc(int fd_left, char *str, t_cookedio *cookedio)
{
	int		pipefd[2];

	pipe(pipefd);
	if (call_dup2(pipefd[0], fd_left) == FAILURE)
		return (FAILURE);
	ft_putstr_fd(str, pipefd[1]);
	protected_close(pipefd[1]);
	update_fdlist(&cookedio->openedfd, pipefd[0], fd_left);
	update_stdtable(cookedio->stdio, pipefd[0], fd_left);
	return (SUCCESS);
}
