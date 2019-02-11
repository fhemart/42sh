/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expr_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:52:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/05 11:57:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_stack		*get_expr_stack(int gsd)
{
	static t_stack	*expressions;

	if (gsd == FT_STGET)
	{
		if (!expressions)
		{
			if (!(expressions = ft_memalloc(sizeof(t_stack))))
				return (NULL);
			ft_stack_init(expressions, 10);
		}
		else
			ft_stack_reset(expressions);
	}
	else if (expressions && gsd == FT_STDEL)
	{
		ft_stack_destroy(expressions);
		free(expressions);
		expressions = NULL;
	}
	return (expressions);
}
