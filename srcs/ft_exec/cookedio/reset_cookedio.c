/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_cookedio.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 21:00:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static void		close_fdlist(t_fdlist *fdlist)
{
	if (!fdlist)
		return ;
	close_fdlist(fdlist->next);
	protected_close(fdlist->fd);
	free(fdlist);
}

void			reset_cookedio(t_cookedio *cdio)
{
	if (!cdio->modified)
		return ;
	close_fdlist(cdio->openedfd);
	cdio->openedfd = NULL;
	cdio->modified = FALSE;
}
