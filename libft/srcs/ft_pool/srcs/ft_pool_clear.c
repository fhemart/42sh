/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pool_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:57:08 by fhemart           #+#    #+#             */
/*   Updated: 2018/07/05 13:12:19 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pool.h"

void			ft_pool_clear(t_pool *pool)
{
	t_pblk		*curs;
	t_stack		*stack;

	curs = pool->blocks;
	if (!curs->next)
		return ;
	ft_pool_close_block(curs->next);
	curs->next = NULL;
	ft_stack_reset((stack = &pool->stack));
	ft_pool_fill(stack, curs, pool->chunksize);
}
