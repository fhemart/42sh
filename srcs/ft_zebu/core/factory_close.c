/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:40:26 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/06 20:05:29 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

static void		factory_close_success(t_tkn_factory *factory, t_tfreturn *ret)
{
	t_exptoken		*expr;

	expr = ft_zebu_get_curr_tok(factory);
	ret->reduced = expr->reduced;
	token_del((t_token**)&expr);
}

static void		clean_and_del_token(t_tkn_grammar *grammar, t_token *token)
{
	t_tkn_expr		*expmodel;

	expmodel = get_expmodel(grammar, token->type);
	if (expmodel && expmodel->cleaner)
		expmodel->cleaner(&((t_exptoken*)token)->reduced);
	token_del(&token);
}

static void		factory_close_error(t_tkn_factory *factory)
{
	t_token			*token;
	t_tkn_grammar	*grammar;

	if (factory->tokencontainer)
		factory_set_error_msg(factory);
	grammar = factory->grammar;
	while ((token = ft_zebu_get_curr_tok(factory)))
		clean_and_del_token(grammar, token);
	while ((token = ft_zebu_get_curr_expr(factory)))
		clean_and_del_token(grammar, token);
}

void			factory_close(t_tkn_factory *factory, t_tfreturn *ret)
{
	ret->final_status = factory->main_status;
	if (ret->final_status == TF_STATUS_END)
		factory_close_success(factory, ret);
	else
		factory_close_error(factory);
}
