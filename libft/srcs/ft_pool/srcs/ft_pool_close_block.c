/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pool_close_block.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:56:12 by fhemart           #+#    #+#             */
/*   Updated: 2018/07/04 18:54:09 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pool.h"

void		ft_pool_close_block(t_pblk *block)
{
	if (!block)
		return ;
	ft_pool_close_block(block->next);
	ft_memdel((void**)&block->buff);
	ft_memdel((void**)&block);
}
