/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pool_giveback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:57:48 by fhemart           #+#    #+#             */
/*   Updated: 2018/07/05 12:17:20 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pool.h"

int				ft_pool_giveback(t_pool *pool, void *elem)
{
	if (ft_stack_add_content(&pool->stack, elem) == FT_STACK_ERROR)
		return (FT_POOL_ERROR);
	return (FT_POOL_SUCCESS);
}
