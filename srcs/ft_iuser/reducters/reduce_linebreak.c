/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_linebreak.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/10 17:52:28 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"
#include "ft_zebu_core.h"
#include "ftsh.h"

static t_bool	complete_command_case(t_tkn_factory *factory)
{
	size_t		size;
	t_token		*tok;

	if ((size = ft_stack_totalsize(factory->expressions)) != 4)
		return (size == 2 ? TRUE : FALSE);
	tok = (t_token*)ft_stack_lookat(factory->expressions, 2);
	if (tok->type == E_SEPARATOR)
		return (TRUE);
	return (FALSE);
}

static t_bool	is_used_type(int type)
{
	if (type == E_COMPOUND_LIST
	|| type == E_AND_OR
	|| type == E_SEPARATOR_OP)
		return (FALSE);
	return (TRUE);
}

static int		add_tok2op_expr(t_iuser *iuser, t_token *tok)
{
	int		*type;
	int		ret;

	ret = tok->type;
	if (is_used_type(ret) && (type = ft_pool_get(iuser->int_pool)))
	{
		*type = ret;
		ft_queue_add(iuser->op_expr, type);
	}
	return (ret);
}

static t_bool	refill_tlex(t_tkn_factory *factory)
{
	t_iuser	*iuser;
	int		type;

	iuser = factory->customparam;
	type = add_tok2op_expr(iuser, ft_zebu_look_curr_tok(factory));
	if (!ft_zebu_notokleft(factory) || complete_command_case(factory) == TRUE)
		return (TRUE);
	if ((iuser->shdata->is_fork & IS_CMDSUBST)
	|| !iuser_refill_src_ps2(iuser, type))
		return (FALSE);
	ft_tlex_resetsrc(iuser->tlex, iuser->src);
	ft_tlex_fill(iuser->tlex);
	factory->main_status = TF_STATUS_ANALYZING;
	return (TRUE);
}

void			*reduce_linebreak(t_tkn_factory *factory, t_exptoken *expr)
{
	t_token	*nl_list;
	int		type;

	(void)expr;
	type = -1;
	if ((nl_list = ft_zebu_look_curr_tok(factory))
	&& (type = nl_list->type) == E_NEWLINE_LIST)
	{
		ft_zebu_get_curr_tok(factory);
		token_del(&nl_list);
	}
	if (!refill_tlex(factory))
		factory->main_status = TF_STATUS_ERROR;
	return (NULL);
}
