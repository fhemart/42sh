/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:28:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 17:47:41 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

int		ft_queue_add(t_queue *queue, void *toadd)
{
	int		index;

	if (ft_queue_isfull(queue) && ft_queue_extend(queue) == FAILURE)
		return (FAILURE);
	index = ++queue->back;
	queue->stock[index % queue->scapacity] = toadd;
	queue->samount++;
	return (SUCCESS);
}
