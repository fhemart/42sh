/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:40:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:02:53 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static const void	*ft_stack_get_propertop(t_stack *stack)
{
	const void	*content;

	content = NULL;
	while ((content = ft_stack_get_content(stack))
	&& ft_stack_removedcheck(stack, content))
		;
	return (content);
}

void				ft_stack_clean(t_stack *stack)
{
	const void	*content;
	const void	*propertop;
	int			i;

	i = -1;
	while ((content = ft_stack_lookat(stack, ++i)))
	{
		if (ft_stack_removedcheck(stack, content))
		{
			if (!(propertop = ft_stack_get_propertop(stack)))
				break ;
			ft_stack_replaceat(stack, i, propertop);
		}
	}
	ft_stack_cleanerexit(stack);
}
