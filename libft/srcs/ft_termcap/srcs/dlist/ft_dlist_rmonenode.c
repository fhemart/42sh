/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_rmonenode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:04:03 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:47:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

static void			rmonenode_if_next(t_cell *next, t_cell *prev, t_term *term)
{
	next->prev = prev;
	if (prev)
		prev->next = next;
	else
		term->prompt->line->head = next;
}

static void			rmonenode_null(t_cell **cell, t_term *term)
{
	(void)term;
	if (cell)
	{
		*cell = NULL;
		term->prompt->line->last = term->prompt->line->current;
	}
	else
	{
		term->prompt->line->head = NULL;
		term->prompt->line->current = NULL;
	}
}

int					ft_dlist_rmonenode(t_term *term, t_cell *cell, t_pool *pool)
{
	t_cell			*next;
	t_cell			*prev;

	next = cell->next;
	prev = cell->prev;
	if (next)
		rmonenode_if_next(next, prev, term);
	else
		rmonenode_null((prev ? &prev->next : NULL), term);
	ft_pool_giveback(pool, cell);
	term->prompt->line->nbelem--;
	return (SUCCESS);
}
