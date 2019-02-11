/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:44:31 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 16:34:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errormsg.h"

int			p_eagain(char *head)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(FT_EAGAIN, 2);
	return (FAILURE);
}

int			p_ebadf(char *head, char *str)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": Bad file descriptor\n", 2);
	return (FAILURE);
}

int			open_error(char *file, int flag)
{
	struct stat		st_stat;

	if (lstat(file, &st_stat) == -1)
		p_enoent(file, SHELL_NAME ": ");
	else if (flag & O_WRONLY)
	{
		if (st_stat.st_mode & S_IFDIR)
			p_eisdir(file, SHELL_NAME ": ");
		else
			p_eacces(file, SHELL_NAME ": ");
	}
	else
		p_eacces(file, SHELL_NAME ": ");
	return (FAILURE);
}

int			print_dir_error(char *arg, int ret)
{
	static void		(*pemsg[4])(char*, char*) = {p_enoent, p_enotdir, \
												p_eacces, p_eloop};

	pemsg[(ret * -1) - 1](arg, SHELL_NAME": cd: ");
	return (EXIT_FAILURE);
}

int			ft_write_error(char *head)
{
	ft_putstr_fd(head, 2);
	ft_putstr_fd("write error: ", 2);
	if (g_last_signal == SIGPIPE)
		ft_putendl_fd(FT_EPIPE, 2);
	else
		ft_putendl_fd(FT_EBADF, 2);
	g_last_signal = 0;
	return (EXIT_FAILURE);
}
