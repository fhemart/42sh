/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_newblock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 01:44:31 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 01:50:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_stack_newblock(t_stack *stack)
{
	t_stack_block	*new;
	size_t			sblock_size;

	sblock_size = sizeof(void*) * stack->chunk_size;
	if (!(new = ft_memalloc(sizeof(t_stack_block)))
		|| !(new->content = ft_memalloc(sblock_size)))
		return (FT_STACK_ERROR);
	if (stack->blocks_count >= stack->max_height
		&& !ft_stack_realloc(stack))
		return (FT_STACK_ERROR);
	stack->blocks[stack->blocks_count++] = new;
	return (FT_STACK_SUCCESS);
}
