/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:24:28 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int	update_line(t_histemark *hem, t_prompt *prpt, char **line, t_shdata *data)
{
	size_t		sz[3];
	char		*nl;

	*hem->strbegin = '\0';
	if (!hem->replace && !(hem->replace = hem->eventsrc))
		return (SUCCESS);
	sz[0] = ft_strlen(*line);
	sz[1] = ft_strlen(hem->replace);
	sz[2] = ft_strlen(hem->strend);
	if (!(nl = ft_strnew(sz[0] + sz[1] + sz[2])))
		return (FAILURE);
	ft_memcpy(nl, *line, sz[0]);
	ft_memcpy(nl + sz[0], hem->replace, sz[1]);
	ft_memcpy(nl + sz[0] + sz[1], hem->strend, sz[2] + 1);
	ft_strdel(line);
	*line = nl;
	if (hem->replace != hem->eventsrc && hem->eventsrc != data->emark_laststr)
		ft_strdel(&hem->eventsrc);
	if (hem->replace != data->emark_laststr)
		ft_strdel(&hem->replace);
	ft_memdel(&prpt->str_line->content);
	prpt->str_line->content = ft_memdup(nl, sz[0] + sz[1] + sz[2] + 1);
	prpt->str_line->content_size = sz[0] + sz[1] + sz[2] + 1;
	hem->strend = (*line) + sz[0] + sz[1];
	return (SUCCESS);
}
