/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_substate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:51:14 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 13:52:00 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

int				check_substate(t_tkn_factory *factory)
{
	t_exptoken		*expr;
	int				id;

	expr = ft_zebu_look_curr_expr(factory);
	id = get_substate_value(expr);
	if (id == factory->tokencontainer->type)
		return (TF_SHIFT);
	if (!try_expanding(factory, expr, id)
	&& close_state(factory, expr) == TF_ENDSTATES)
		reduce(factory);
	return (TF_CONTINUE);
}
