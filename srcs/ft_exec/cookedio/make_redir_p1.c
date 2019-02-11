/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redir_p1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:59:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 01:13:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int			iof_less(int fd_left, char *str, t_cookedio *cookedio)
{
	int	fd_right;

	if ((fd_right = open(str, O_RDONLY)) == -1)
		return (open_error(str, O_RDONLY));
	if (call_dup2(fd_right, fd_left) == FAILURE)
		return (FAILURE);
	update_fdlist(&cookedio->openedfd, fd_right, fd_left);
	update_stdtable(cookedio->stdio, fd_right, fd_left);
	cookedio->modified = TRUE;
	return (SUCCESS);
}

int			iof_sand(int fd_left, char *str, t_cookedio *cookedio)
{
	int		fd_right;
	int		close_fd;

	if ((fd_right = get_rh_from_fd(str, &close_fd)) == -1 && close_fd == FALSE)
		return (FAILURE);
	if (call_dup2(fd_right, fd_left) == FAILURE)
		return (FAILURE);
	update_fdlist(&cookedio->openedfd, fd_right, fd_left);
	update_stdtable(cookedio->stdio, fd_right, fd_left);
	cookedio->modified = TRUE;
	return (SUCCESS);
}

int			iof_great(int fd_left, char *str, t_cookedio *cookedio)
{
	int	fd_right;

	if ((fd_right = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
		return (open_error(str, O_WRONLY | O_CREAT | O_TRUNC));
	if (fd_right != fd_left && call_dup2(fd_right, fd_left) == FAILURE)
		return (FAILURE);
	update_fdlist(&cookedio->openedfd, fd_right, fd_left);
	update_stdtable(cookedio->stdio, fd_right, fd_left);
	cookedio->modified = TRUE;
	return (SUCCESS);
}

static int	copy_fd(int fdnew, int fdcopy)
{
	int		tmp;
	int		err;

	if ((tmp = dup(fdnew)) == -1 || dup2(tmp, fdcopy) == -1)
		err = FAILURE;
	else
		err = SUCCESS;
	protected_close(tmp);
	if (err == FAILURE)
		return (p_ebadf(SHELL_NAME ": ", ft_static_itoa(fdnew)));
	return (SUCCESS);
}

int			iof_lgand(int fd_left, char *str, t_cookedio *cookedio)
{
	int		fd_right;
	int		close_fd;

	fd_right = get_rh_from_fd(str, &close_fd);
	if (fd_right == -1)
	{
		if (close_fd == FALSE)
			return (FAILURE);
		protected_close(fd_left);
		update_stdtable(cookedio->stdio, fd_left, fd_right);
	}
	else if (copy_fd(fd_right, fd_left) == FAILURE)
		return (FAILURE);
	update_fdlist(&cookedio->openedfd, fd_right, fd_left);
	cookedio->modified = TRUE;
	return (SUCCESS);
}
