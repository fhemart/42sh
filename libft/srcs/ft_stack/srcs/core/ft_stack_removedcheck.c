/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_removedcheck.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 02:01:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/07 03:28:42 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_bool			ft_stack_removedcheck(t_stack *stack, const void *elem)
{
	t_stack_cleaner		*cleaner;

	cleaner = stack->cleaner;
	while (cleaner)
	{
		if (elem >= cleaner->from && elem < cleaner->to)
		{
			ft_stack_cleanerdelfrom(stack, cleaner);
			return (TRUE);
		}
		cleaner = cleaner->next;
	}
	return (FALSE);
}
