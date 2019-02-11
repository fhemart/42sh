/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_looktop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 02:31:16 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/24 01:23:12 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void const		*ft_stack_looktop(t_stack *stack)
{
	t_stack_block	*block;
	void			*content;

	if (ft_stack_isempty(stack))
		return (FT_STACK_EMPTY);
	block = stack->blocks[stack->blocks_count - 1];
	content = block->content[block->size - 1];
	return ((void const*)content);
}
