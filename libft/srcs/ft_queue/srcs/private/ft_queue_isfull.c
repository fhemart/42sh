/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_isfull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:28:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/06/06 13:40:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

t_bool		ft_queue_isfull(t_queue *queue)
{
	return (queue->samount == queue->scapacity);
}
