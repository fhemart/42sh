/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pool_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:54:10 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/16 19:01:03 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pool.h"

t_pool			*ft_pool_new(size_t blocksize, size_t chunksize)
{
	t_pool	*new_pool;
	t_stack	*stack;

	if (!(new_pool = ft_memalloc(sizeof(t_pool))))
		return (NULL);
	new_pool->blocksize = blocksize;
	new_pool->chunksize = chunksize;
	stack = &new_pool->stack;
	if (!(new_pool->blocks = ft_pool_new_block(blocksize * chunksize))
	|| ft_stack_init(stack, blocksize) == FT_STACK_ERROR
	|| ft_pool_fill(stack, new_pool->blocks, chunksize) == FT_POOL_ERROR)
	{
		ft_pool_close(&new_pool);
		return (NULL);
	}
	return (new_pool);
}
