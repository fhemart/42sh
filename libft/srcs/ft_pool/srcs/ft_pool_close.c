/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pool_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:56:12 by fhemart           #+#    #+#             */
/*   Updated: 2018/07/04 18:54:12 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pool.h"

void		ft_pool_close(t_pool **pool)
{
	t_pool	*dummy;

	if (!(dummy = *pool))
		return ;
	ft_pool_close_block(dummy->blocks);
	ft_stack_destroy(&dummy->stack);
	ft_memdel((void**)pool);
}
