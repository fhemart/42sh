/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pool_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:57:48 by fhemart           #+#    #+#             */
/*   Updated: 2018/07/05 12:47:01 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pool.h"

int				ft_pool_fill(t_stack *stack, t_pblk *block, size_t size)
{
	char		*buff;
	int			psize;
	int			i;

	buff = block->buff;
	psize = block->totalsize;
	i = 0;
	while (i < psize)
	{
		if (!ft_stack_add_content(stack, buff + i))
			return (FT_POOL_ERROR);
		i += size;
	}
	return (FT_POOL_SUCCESS);
}
