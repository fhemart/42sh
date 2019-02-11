/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_isempty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:09:38 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/23 00:21:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_bool			ft_stack_isempty(t_stack *stack)
{
	if (!stack->blocks_count || !stack->blocks[0][0].size)
		return (TRUE);
	return (FALSE);
}
