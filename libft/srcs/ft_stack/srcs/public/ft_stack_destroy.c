/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 02:36:30 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/07 03:47:02 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_stack_destroy(t_stack *stack)
{
	while (stack->blocks_count)
	{
		free(stack->blocks[--stack->blocks_count]->content);
		free(stack->blocks[stack->blocks_count]);
	}
	free(stack->blocks);
	ft_bzero((void*)stack, sizeof(t_stack));
	return (0);
}
