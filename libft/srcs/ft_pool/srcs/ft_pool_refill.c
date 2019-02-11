/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pool_refill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:55:13 by fhemart           #+#    #+#             */
/*   Updated: 2018/08/07 11:10:41 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pool.h"

static t_pblk	*get_last(t_pblk *block)
{
	if (!block->next)
		return (block);
	return (get_last(block->next));
}

int				ft_pool_refill(t_stack *stack, t_pblk *block, size_t size)
{
	t_pblk	*curs;

	curs = get_last(block);
	if (!(curs->next = ft_pool_new_block(block->totalsize)))
		return (-1);
	return (ft_pool_fill(stack, curs->next, size));
}
