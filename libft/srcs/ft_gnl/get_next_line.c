/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:31:44 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/04 18:57:09 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		create_newline(char **save, char **line)
{
	char	*tmp;
	size_t	len;

	if (!*save)
		return (0);
	if (!(tmp = ft_strchr(*save, '\n')))
		len = ft_strlen(*save);
	else
		len = (tmp) - (*save);
	if (!(*line = ft_strndup(*save, len)))
		return (-1);
	if ((*save)[len])
		tmp = (*save)[len] ? ft_strdup((*save) + len + 1) : NULL;
	ft_strdel(save);
	*save = tmp;
	return (1);
}

int		read_file(int fd, char **line, char **save)
{
	char	buff[BUFF_SIZE + 1];
	int		read_ret;

	while ((read_ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_ret] = '\0';
		ft_strjoin_proper(save, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (create_newline(save, line));
}

int		get_next_line(int fd, char **line)
{
	static char		*save;

	if (fd < 0)
		return (-1);
	if (save && ft_strchr(save, '\n'))
		return (create_newline(&save, line));
	return (read_file(fd, line, &save));
}
