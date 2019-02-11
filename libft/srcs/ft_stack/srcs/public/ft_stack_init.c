/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 01:45:08 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 01:50:42 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_stack_init(t_stack *stack, size_t chunk_size)
{
	if (!stack)
		return (FT_STACK_ERROR);
	ft_bzero(stack, sizeof(t_stack));
	stack->blocks = ft_memalloc(sizeof(t_stack_block*) * INITIAL_STACK_SIZE);
	if (!stack->blocks)
		return (FT_STACK_ERROR);
	stack->max_height = INITIAL_STACK_SIZE;
	stack->chunk_size = chunk_size;
	return (FT_STACK_SUCCESS);
}
