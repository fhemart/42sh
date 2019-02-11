/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pool_new_block.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:54:10 by fhemart           #+#    #+#             */
/*   Updated: 2018/07/04 18:53:43 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pool.h"

t_pblk			*ft_pool_new_block(size_t totalsize)
{
	t_pblk			*block;

	if (!(block = ft_memalloc(sizeof(t_pool))))
		return (NULL);
	if (!(block->buff = ft_memalloc(totalsize)))
	{
		free(block);
		return (NULL);
	}
	block->totalsize = totalsize;
	return (block);
}
