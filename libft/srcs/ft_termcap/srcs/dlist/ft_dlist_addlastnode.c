/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_addlastnode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:08:32 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/03 23:51:47 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

int				ft_dlist_addlastnode(t_line *root, char c, t_pool *pool)
{
	t_cell		*tmp;

	if (!(tmp = ft_dlist_createnode(pool)))
		return (FAILURE);
	tmp->c = c;
	tmp->prev = root->last;
	root->current = tmp;
	root->last->next = tmp;
	root->last = tmp;
	return (SUCCESS);
}
