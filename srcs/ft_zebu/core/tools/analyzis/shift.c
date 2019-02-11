/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:49:57 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 13:52:19 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

void			shift(t_tkn_factory *factory)
{
	t_exptoken *expr;

	expr = ft_zebu_look_curr_expr(factory);
	ft_stack_add_content(factory->tokens, factory->tokencontainer);
	factory->tokencontainer = NULL;
	expr->substate++;
	expr->validstate = TF_UNVALIDSTATE;
	reset_blacklist(&factory->expr_blacklist);
}
