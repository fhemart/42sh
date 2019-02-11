/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_totalsize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 01:42:10 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/25 02:59:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	ft_stack_totalsize(t_stack *stack)
{
	size_t height;

	if (ft_stack_isempty(stack))
		return (0);
	height = stack->blocks_count - 1;
	return (height * stack->chunk_size + stack->blocks[height]->size);
}
