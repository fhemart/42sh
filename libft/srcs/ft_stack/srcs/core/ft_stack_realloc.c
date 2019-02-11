/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_realloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 01:43:21 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/07 03:48:53 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_stack_realloc(t_stack *stack)
{
	t_stack_block	**new;
	int				i;

	stack->max_height += INITIAL_STACK_SIZE;
	if (!(new = ft_memalloc(sizeof(t_stack_block*) * stack->max_height)))
		return (FT_STACK_ERROR);
	i = -1;
	while (++i < (int)stack->blocks_count)
		new[i] = stack->blocks[i];
	free(stack->blocks);
	stack->blocks = new;
	return (FT_STACK_SUCCESS);
}
