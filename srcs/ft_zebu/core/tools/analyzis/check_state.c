/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:47:55 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 14:54:00 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

static t_bool	continue_state_check(t_tkn_factory *factory, \
									t_exptoken *expr, t_token *tok)
{
	if (!substate_match_token(expr, tok))
	{
		if (close_state(factory, expr) == TF_ENDSTATES)
			reduce(factory);
		return (FALSE);
	}
	return (TRUE);
}

int				check_state(t_tkn_factory *factory)
{
	t_exptoken	*expr;
	t_token		*tkn;
	int			tssize;
	int			offset;

	if (!(expr = ft_zebu_look_curr_expr(factory))
	&& fill_container(factory) == TF_LEXEND)
		return (TF_ENDSTATES);
	tssize = (int)ft_stack_totalsize(factory->tokens);
	expr->substate = 0;
	offset = expr->tsoffset;
	while (offset < tssize)
	{
		if (substate_match_id(expr, expr->id))
			expr->isrecursive = TRUE;
		tkn = (t_token*)ft_stack_lookat(factory->tokens, offset);
		if (!continue_state_check(factory, expr, tkn))
			return (TF_CHECKSTATE);
		offset++;
		expr->substate++;
	}
	return (TF_CONTINUE);
}
