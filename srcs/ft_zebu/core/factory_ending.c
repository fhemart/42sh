/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_ending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:37:54 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 12:42:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

static void		factory_set_status(t_tkn_factory *factory)
{
	const t_token	*tok;

	if (factory->main_status == TF_STATUS_ANALYZING)
		return ;
	tok = ft_stack_looktop(factory->tokens);
	if (ft_stack_totalsize(factory->tokens) != 1
	|| tok->type != factory->grammar->startingexpr)
	{
		factory->main_status = TF_STATUS_ERROR;
		factory_set_error_msg(factory);
	}
	else
		factory->main_status = TF_STATUS_END;
}

void			factory_ending(t_tkn_factory *factory)
{
	t_stack			*exprstack;
	t_exptoken		*expr;
	int				id;

	exprstack = factory->expressions;
	while (ft_stack_totalsize(exprstack) > 0
	&& (factory->main_status & TF_STATUS_CLOSING))
	{
		expr = (t_exptoken*)ft_stack_looktop(exprstack);
		check_state(factory);
		if (expr == (t_exptoken*)ft_stack_looktop(exprstack))
		{
			if (expr->substate > 0
			&& id_isexpr((id = get_substate_value(expr))))
			{
				if (!try_expanding(factory, expr, id))
					add_expr_to_blacklist(&factory->expr_blacklist, id);
				else
					continue ;
			}
			if (close_state(factory, expr) == TF_ENDSTATES)
				reduce(factory);
		}
	}
	factory_set_status(factory);
}
