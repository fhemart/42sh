/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:28:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/02 12:16:49 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

t_queue		*ft_queue_new(int stock_capacity)
{
	t_queue		*new;

	if (stock_capacity <= 0 || !(new = (t_queue*)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	if (!(new->stock = (void**)malloc(sizeof(void*) * stock_capacity)))
	{
		free(new);
		return (NULL);
	}
	new->scapacity = stock_capacity;
	new->back = -1;
	return (new);
}
