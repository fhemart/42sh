/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_addfirstnode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:07:48 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/08 19:27:33 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

int				ft_dlist_addfirstnode(t_line *root, char c, t_pool *pool)
{
	t_cell		*first;

	if (root->current)
	{
		first = root->head;
		if (!(root->head = ft_dlist_createnode(pool)))
			return (FAILURE);
		root->head->c = c;
		root->head->next = first;
		first->prev = root->head;
		if (!root->last)
			root->last = first;
	}
	else
	{
		if (!(root->head = ft_dlist_createnode(pool)))
			return (FAILURE);
		root->head->c = c;
		root->head->next = NULL;
		root->head->prev = NULL;
		root->last = root->head;
	}
	root->current = root->head;
	return (SUCCESS);
}
