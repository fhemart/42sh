/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_replaceat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:28:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 17:55:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

int			ft_queue_replaceat(t_queue *queue, void *rep, int at)
{
	if (at >= queue->samount)
		return (FAILURE);
	queue->stock[(queue->front + at) % queue->scapacity] = rep;
	return (SUCCESS);
}
