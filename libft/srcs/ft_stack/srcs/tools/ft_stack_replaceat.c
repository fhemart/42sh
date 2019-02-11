/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_replaceat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 02:08:39 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:03:33 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void			ft_stack_replaceat(t_stack *stack, int index, \
									const void *newcontent)
{
	t_stack_block	*block;

	if (ft_stack_isempty(stack) || index >= (int)ft_stack_totalsize(stack))
		return ;
	block = stack->blocks[index / stack->chunk_size];
	block->content[index % stack->chunk_size] = (void*)newcontent;
}
