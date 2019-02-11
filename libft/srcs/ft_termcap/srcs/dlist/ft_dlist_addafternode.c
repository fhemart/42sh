/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_addafternode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:09:09 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/03 23:46:58 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

int				ft_dlist_addafternode(t_line *root, char c, t_pool *pool)
{
	t_cell		*tmp;

	if (!(tmp = ft_dlist_createnode(pool)))
		return (FAILURE);
	tmp->c = c;
	tmp->prev = root->current;
	tmp->next = root->current->next;
	root->current->next = tmp;
	if (tmp->next)
		tmp->next->prev = tmp;
	root->current = tmp;
	return (SUCCESS);
}
