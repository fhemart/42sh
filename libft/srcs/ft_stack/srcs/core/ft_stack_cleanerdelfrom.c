/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_cleanerdelfrom.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:35:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/07 02:28:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void			ft_stack_cleanerdelfrom(t_stack *stack, t_stack_cleaner *del)
{
	if (!del || (del->count && --del->count))
		return ;
	if (!del->previous)
		stack->cleaner = del->next;
	else
		del->previous->next = del->next;
	free(del);
}
