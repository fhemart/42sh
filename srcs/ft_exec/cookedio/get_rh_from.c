/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rh_from.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:59:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 21:04:17 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int		get_rh_from_file1(char *str, int *close_fd)
{
	int	rh;

	*close_fd = 0;
	if ((rh = open(str, O_RDONLY)) != -1)
		return (rh);
	return (open_error(str, O_RDONLY));
}

int		get_rh_from_file2(char *str, int *close_fd)
{
	int	rh;

	*close_fd = 0;
	if ((rh = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0664)) != -1)
		return (rh);
	return (open_error(str, O_WRONLY | O_CREAT | O_TRUNC));
}

int		get_rh_from_file3(char *str, int *close_fd)
{
	int	rh;

	*close_fd = 0;
	if ((rh = open(str, O_WRONLY | O_CREAT | O_APPEND, 0664)) != -1)
		return (rh);
	return (open_error(str, O_WRONLY | O_CREAT | O_APPEND));
}

int		get_rh_from_fd(char *str, int *close_fd)
{
	int		rh;

	if ((*close_fd = ft_strequ(str, "-")) == TRUE)
		return (-1);
	if (ft_strlen(str) > 4 || (rh = ft_atoi(str)) > IUSER_MAX_IOFD)
	{
		return (p_ebadf(SHELL_NAME ": ", str));
	}
	else if (!ft_strisdigit(str))
		return (p_eambr(SHELL_NAME ": ", str));
	return (rh);
}
