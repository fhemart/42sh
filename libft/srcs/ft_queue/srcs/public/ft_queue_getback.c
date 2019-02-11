/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_getback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:28:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/06 13:48:50 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void		*ft_queue_getback(t_queue *queue)
{
	if (ft_queue_isempty(queue))
		return (NULL);
	queue->samount--;
	return (queue->stock[queue->back-- % queue->scapacity]);
}
