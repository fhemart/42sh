/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:12:23 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 12:12:37 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

int				close_state(t_tkn_factory *factory, t_exptoken *expr)
{
	size_t		stack_cursor;

	stack_cursor = expr->tsoffset + expr->substate;
	if (stack_cursor == ft_stack_totalsize(factory->tokens)
		&& substate_match_id(expr, EXPR_ENDOFSTATE))
		expr->validstate = expr->state;
	if (expr->state + 1 == expr->maxstate)
		return (TF_LASTSTATE);
	expr->state++;
	expr->substate = 0;
	return (TF_CONTINUE);
}
