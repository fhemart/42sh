/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_append_entries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 20:02:34 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	recurs_write_entries(int fd, t_histentry *entry, t_bool unsavedonly)
{
	if (!entry)
		return (SUCCESS);
	if (recurs_write_entries(fd, entry->prev, unsavedonly) == FAILURE)
		return (FAILURE);
	if (unsavedonly)
	{
		if (entry->saved == TRUE)
			return (SUCCESS);
		entry->saved = TRUE;
	}
	if (ft_putstr_fd(entry->string, fd) == FAILURE
	|| ft_putchar_fd('\n', fd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int			hist_write_entries(t_shhist *hist, char *histfile)
{
	int		fd;
	int		ret;

	if ((fd = open(histfile, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		return (FAILURE);
	ret = recurs_write_entries(fd, hist->entries, FALSE);
	close(fd);
	return (ret);
}

int			hist_append_entries(t_shhist *hist, char *histfile)
{
	int		fd;
	int		ret;

	if ((fd = open(histfile, O_RDWR | O_CREAT | O_APPEND, 0644)) == -1)
		return (FAILURE);
	ret = recurs_write_entries(fd, hist->entries, TRUE);
	close(fd);
	return (ret);
}
