/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/06 20:02:02 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"
#include "ft_iuser.h"

static t_queue	*get_first_and_or(t_tkn_factory *factory, t_exptoken *expr)
{
	t_exptoken	*tmp;
	t_queue		*ret;

	ret = NULL;
	expr->state = expr->validstate;
	expr->substate = 1;
	while (!substate_match_id(expr, EXPR_ENDOFSTATE))
	{
		expr->substate++;
		tmp = ft_zebu_get_curr_tok(factory);
		if (tmp->id == E_AND_OR)
			ret = tmp->reduced;
		token_del((t_token**)&tmp);
	}
	return (ret);
}

static t_queue	*create_new_and_or(t_andor *and_orstruct)
{
	t_queue		*and_or;

	if (!(and_or = ft_queue_new(4))
	&& !(and_or = ft_queue_new(2)))
	{
		del_andorstruct(&and_orstruct);
		return (NULL);
	}
	ft_queue_add(and_or, and_orstruct);
	return (and_or);
}

static void		*set_andorerror(t_tkn_factory *factory, t_exptoken *last_expr)
{
	del_pipeline((t_command**)&last_expr->reduced);
	token_del((t_token**)&last_expr);
	factory->main_status = TF_STATUS_ERROR;
	return (NULL);
}

void			*reduce_and_or(t_tkn_factory *factory, t_exptoken *expr)
{
	t_exptoken	*last_expr;
	t_queue		*and_or;
	t_andor		*and_orstruct;

	last_expr = ft_zebu_get_curr_tok(factory);
	if (!(and_orstruct = new_andor(last_expr->reduced, expr->validstate)))
		return (set_andorerror(factory, last_expr));
	if ((and_or = get_first_and_or(factory, expr)))
	{
		if (ft_queue_add(and_or, and_orstruct) == -1)
		{
			del_andorstruct(&and_orstruct);
			factory->main_status = TF_STATUS_ERROR;
		}
	}
	else if (!(and_or = create_new_and_or(and_orstruct)))
		factory->main_status = TF_STATUS_ERROR;
	if (expr->validstate != 0)
		remove_opexpr(factory->customparam);
	token_del((t_token**)&last_expr);
	return (and_or);
}
