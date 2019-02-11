/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_extend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:28:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 17:47:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

int			ft_queue_extend(t_queue *queue)
{
	void	**newstock;
	int		newcap;
	int		i;

	newcap = queue->scapacity * 2;
	if (queue->scapacity >= 0x40000000
	|| !(newstock = (void**)malloc(sizeof(void*) * newcap)))
		return (FAILURE);
	i = queue->front - 1;
	while (++i <= queue->back)
		newstock[i - queue->front] = queue->stock[i % queue->scapacity];
	free(queue->stock);
	queue->stock = newstock;
	queue->front = 0;
	queue->back = queue->samount - 1;
	queue->scapacity = newcap;
	return (SUCCESS);
}
