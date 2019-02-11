/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 01:45:44 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 01:45:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_stack_add_content(t_stack *stack, void *content)
{
	size_t		height;

	if ((!stack->blocks_count
		|| stack->blocks[stack->blocks_count - 1]->size == stack->chunk_size)
		&& !ft_stack_newblock(stack))
		return (FT_STACK_ERROR);
	height = stack->blocks_count - 1;
	stack->blocks[height]->content[stack->blocks[height]->size++] = content;
	return (1);
}
