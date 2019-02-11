/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_addbeforenode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:10:16 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/08 18:54:01 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

int				ft_dlist_addbeforenode(t_cell *cell, char c, t_pool *pool)
{
	t_cell		*tmp;

	if (!(tmp = ft_dlist_createnode(pool)))
		return (FAILURE);
	tmp->c = c;
	tmp->prev = cell->prev;
	tmp->next = cell;
	cell->prev->next = tmp;
	cell->prev = tmp;
	return (SUCCESS);
}
