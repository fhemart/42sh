/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pool_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:56:12 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/16 19:00:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pool.h"

static void	*clean_ret(void *ret, size_t chunksize)
{
	if (!ret)
		return (NULL);
	ft_bzero(ret, chunksize);
	return (ret);
}

void		*ft_pool_get(t_pool *pool)
{
	t_stack	*stack;
	void	*ret;

	stack = &pool->stack;
	if (!(ret = ft_stack_get_content(stack))
	&& ft_pool_refill(stack, pool->blocks, pool->chunksize) == FT_POOL_SUCCESS)
		ret = ft_stack_get_content(stack);
	return (clean_ret(ret, pool->chunksize));
}
