/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_cleaneradd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:22:45 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/07 03:26:34 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int				ft_stack_cleaneradd(t_stack *stack, void *content, \
									size_t content_size, size_t count)
{
	t_stack_cleaner *new;

	if (!(new = ft_stack_cleanernew(content, content_size, count)))
		return (0);
	new->next = stack->cleaner;
	stack->cleaner = new;
	if (new->next)
		new->next->previous = new;
	return (1);
}
