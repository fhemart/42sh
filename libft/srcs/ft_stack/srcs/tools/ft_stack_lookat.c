/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_lookat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 01:51:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:03:17 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void const		*ft_stack_lookat(t_stack *stack, int i)
{
	t_stack_block	*block;

	if (ft_stack_isempty(stack) || i >= (int)ft_stack_totalsize(stack))
		return (FT_STACK_EMPTY);
	block = stack->blocks[i / stack->chunk_size];
	return (block->content[i % stack->chunk_size]);
}
