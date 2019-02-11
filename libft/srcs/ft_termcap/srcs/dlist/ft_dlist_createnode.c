/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_createnode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:06:55 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 01:15:40 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_cell			*ft_dlist_createnode(t_pool *pool)
{
	t_cell		*cell;

	if ((cell = ft_pool_get(pool)))
		cell->skip = FALSE;
	return (cell);
}
