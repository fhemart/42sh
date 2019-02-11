/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:50:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 14:59:03 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

void		factory_init(t_tkn_factory *factory, t_tlexicon *tlex, void *cparam)
{
	t_tkn_grammar	*grammar;
	int				expr_id;
	t_exptoken		*start;

	ft_bzero(factory, sizeof(t_tkn_factory));
	if (factory_get_stacks(factory) == -1 || factory_init_pools() == -1)
	{
		factory->main_status = TF_STATUS_ERROR;
		return ;
	}
	factory->lex = tlex;
	grammar = tlex->grammar;
	expr_id = grammar->startingexpr;
	start = new_exptoken(expr_id, &grammar->expr[(expr_id & ~EXPR_OFFSET_VAL)]);
	if (!start)
		factory->main_status = TF_STATUS_ERROR;
	ft_stack_add_content(factory->expressions, start);
	factory->grammar = grammar;
	factory->customparam = cparam;
	factory->main_status = TF_STATUS_ANALYZING;
}
