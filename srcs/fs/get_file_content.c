/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:36:25 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/17 15:36:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

char		*get_file_content(char *fname)
{
	char		*content;
	int			fd;
	struct stat	st_stat;

	if ((fd = open(fname, O_RDONLY)) == -1)
		return (NULL);
	if (fstat(fd, &st_stat) == -1 || st_stat.st_size == 0
	|| !(content = ft_strnew(st_stat.st_size)))
	{
		close(fd);
		return (NULL);
	}
	read(fd, content, st_stat.st_size);
	content[st_stat.st_size] = '\0';
	close(fd);
	return (content);
}
