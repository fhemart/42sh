/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/06 19:01:36 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"
#include "ft_iuser.h"

static t_command	*get_first_pl(t_tkn_factory *factory, t_exptoken *expr)
{
	t_exptoken	*tmp;
	t_command	*ret;

	ret = NULL;
	expr->state = expr->validstate;
	expr->substate = 1;
	while (!substate_match_id(expr, EXPR_ENDOFSTATE))
	{
		expr->substate++;
		tmp = ft_zebu_get_curr_tok(factory);
		if (tmp->id == E_PIPELINE)
			ret = tmp->reduced;
		token_del((t_token**)&tmp);
	}
	return (ret);
}

void				*reduce_pipeline(t_tkn_factory *factory, t_exptoken *expr)
{
	t_exptoken	*last_expr;
	t_command	*pipeline;
	t_command	*cmd;

	last_expr = ft_zebu_get_curr_tok(factory);
	cmd = last_expr->reduced;
	if (!ft_stack_isempty(factory->tokens)
	&& (pipeline = get_first_pl(factory, expr)))
		ft_lstadd((t_list**)&pipeline, (t_list*)cmd);
	else
		pipeline = cmd;
	if (expr->validstate != 0)
		remove_opexpr(factory->customparam);
	token_del((t_token**)&last_expr);
	return (pipeline);
}
