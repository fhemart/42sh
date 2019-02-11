/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_cleanerexit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 02:11:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/07 02:21:53 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void			ft_stack_cleanerexit(t_stack *stack)
{
	t_stack_cleaner		*cleaner;

	if (FT_STACK_SHOW_WARNING && stack->cleaner)
		ft_putendl_fd(FT_STACK_NOTEMPTYCLEANER, 2);
	while (stack->cleaner)
	{
		cleaner = stack->cleaner;
		stack->cleaner = cleaner->next;
		free(cleaner);
	}
}
