/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:11:19 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 13:52:32 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

static void		shift_expression(t_tkn_factory *factory)
{
	t_exptoken		*expr;
	t_exptoken		*next;

	expr = ft_zebu_get_curr_expr(factory);
	ft_stack_add_content(factory->tokens, expr);
	next = ft_zebu_look_curr_expr(factory);
	if (next)
	{
		reset_blacklist(&factory->expr_blacklist);
		next->validstate = TF_UNVALIDSTATE;
		next->substate++;
	}
	if (expr->isrecursive)
		ft_stack_add_content(factory->expressions, exptoken_freshdup(expr));
}

void			reduce(t_tkn_factory *factory)
{
	t_exptoken	*expr;
	t_tkn_expr	*expmodel;

	expr = ft_zebu_look_curr_expr(factory);
	if (expr->validstate == TF_UNVALIDSTATE)
		return (discard_expr(factory->expressions, factory));
	expmodel = get_expmodel(factory->grammar, expr->id);
	expr->reduced = expmodel->reducer(factory, expr);
	shift_expression(factory);
}
