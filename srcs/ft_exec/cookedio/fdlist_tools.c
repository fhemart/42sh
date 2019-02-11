/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdlist_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:59:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 22:19:55 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static t_fdlist	*new_fdlist(int fd)
{
	t_fdlist	*new;

	if (!(new = (t_fdlist*)malloc(sizeof(t_fdlist))))
		return (NULL);
	new->next = NULL;
	new->fd = fd;
	return (new);
}

static t_fdlist	*find_fdlist(t_fdlist *fdl, int fd)
{
	while (fdl)
	{
		if (fdl->fd == fd)
			return (fdl);
		fdl = fdl->next;
	}
	return (NULL);
}

t_fdlist		*update_fdlist(t_fdlist **fdlhead, int newfd, int oldfd)
{
	t_fdlist	*dummy;
	t_fdlist	*new_list;

	if ((dummy = find_fdlist(*fdlhead, oldfd)))
		dummy->fd = newfd;
	else
	{
		new_list = new_fdlist(newfd);
		ft_lstadd((t_list**)fdlhead, (t_list*)new_list);
	}
	return (*fdlhead);
}
