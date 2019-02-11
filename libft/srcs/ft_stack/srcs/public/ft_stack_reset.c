/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 02:36:30 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/27 23:14:50 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_stack_reset(t_stack *stack)
{
	if (ft_stack_isempty(stack))
		return (0);
	while (stack->blocks_count > 1)
	{
		free(stack->blocks[--stack->blocks_count]->content);
		free(stack->blocks[stack->blocks_count]);
	}
	stack->blocks[0]->size = 0;
	return (0);
}
