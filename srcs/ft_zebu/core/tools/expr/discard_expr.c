/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discard_expr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:32:07 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 13:57:22 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

void			discard_expr(t_stack *expressions, t_tkn_factory *factory)
{
	t_exptoken		*expr;
	t_exptoken		*next;

	expr = ft_stack_get_content(expressions);
	next = (t_exptoken*)ft_stack_looktop(expressions);
	if (next)
		add_expr_to_blacklist(&factory->expr_blacklist, expr->id);
	token_del((t_token**)&expr);
	fill_container(factory);
}
