/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_inputlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/30 16:56:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

static t_queue	*get_first_inputlist(t_tkn_factory *factory, t_exptoken *expr)
{
	t_exptoken	*tmp;
	t_queue		*ret;

	ret = NULL;
	expr->state = expr->validstate;
	while (!substate_match_id(expr, EXPR_ENDOFSTATE))
	{
		expr->substate++;
		tmp = ft_zebu_get_curr_tok(factory);
		if (tmp->id == E_LIST || tmp->id == E_TERM)
			ret = tmp->reduced;
		token_del((t_token**)&tmp);
	}
	return (ret);
}

static t_queue	*create_new_inputlist(t_inputlist *list)
{
	t_queue		*inputlist;

	if (!(inputlist = ft_queue_new(4))
	&& !(inputlist = ft_queue_new(2)))
	{
		del_inputliststruct(&list);
		return (NULL);
	}
	ft_queue_add(inputlist, list);
	return (inputlist);
}

static void		*set_listerror(t_tkn_factory *factory, t_exptoken *last_expr)
{
	del_andor((t_queue**)&last_expr->reduced);
	factory->main_status = TF_STATUS_ERROR;
	return (NULL);
}

static void		*get_last_expr(t_tkn_factory *factory, t_exptoken *expr)
{
	t_exptoken	*last_expr;

	last_expr = ft_zebu_get_curr_tok(factory);
	if (last_expr->id == E_LINEBREAK)
	{
		expr->substate = 2;
		token_del((t_token**)&last_expr);
		last_expr = ft_zebu_get_curr_tok(factory);
	}
	else
		expr->substate = 1;
	return (last_expr);
}

void			*reduce_list(t_tkn_factory *factory, t_exptoken *expr)
{
	t_exptoken	*last_expr;
	t_queue		*inputlist;
	t_inputlist	*list;

	if (expr->id == E_TERM && expr->validstate == 1)
		return (get_first_inputlist(factory, expr));
	last_expr = get_last_expr(factory, expr);
	if (!(list = new_inputlist(last_expr->reduced, 0)))
		return (set_listerror(factory, last_expr));
	if (!ft_stack_isempty(factory->tokens)
	&& (inputlist = get_first_inputlist(factory, expr)))
	{
		if (ft_queue_add(inputlist, list) == -1)
		{
			del_inputliststruct(&list);
			factory->main_status = TF_STATUS_ERROR;
		}
	}
	else if (!(inputlist = create_new_inputlist(list)))
		factory->main_status = TF_STATUS_ERROR;
	token_del((t_token**)&last_expr);
	return (inputlist);
}
