/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_clean_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:28:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/02 12:16:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void		ft_queue_clean_content(t_queue *queue, void (*clean)(void*))
{
	void	*content;

	while (!ft_queue_isempty(queue))
	{
		content = ft_queue_get(queue);
		clean(content);
	}
}
