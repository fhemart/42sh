/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_rmnode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:11:47 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/22 19:03:32 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

static void			rmnode_if_prev(t_line *root, t_cell *tmp)
{
	root->current = root->current->prev;
	root->current->next = tmp;
	if (tmp)
		root->current->next->prev = root->current;
}

static void			rmnode_elseif_next(t_line *root, t_cell *tmp)
{
	root->current = tmp;
	root->current->prev = NULL;
}

static void			rmnode_if_todel(t_line *root, t_cell *todel)
{
	if (todel == root->head)
		root->head = root->current;
	else if (todel == root->last)
		root->last = root->current;
}

int					ft_dlist_rmnode(t_line *root, t_pool *pool)
{
	t_cell			*tmp;
	t_cell			*todel;

	tmp = root->current->next;
	todel = root->current;
	if (!root)
		return (FAILURE);
	if (root->current)
	{
		if (root->current->prev)
			rmnode_if_prev(root, tmp);
		else if (root->current->next)
			rmnode_elseif_next(root, tmp);
		else
			root->current = NULL;
		rmnode_if_todel(root, todel);
		ft_pool_giveback(pool, todel);
		root->nbelem--;
	}
	return (SUCCESS);
}
