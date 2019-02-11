/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/30 16:11:01 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"
#include "ft_iuser.h"

void		*reduce_subshell(t_tkn_factory *factory, t_exptoken *expr)
{
	t_exptoken	*last_expr;
	t_subshell	*subshell;
	t_queue		*ilist;
	int			i;

	(void)expr;
	i = -1;
	while (++i < 4)
	{
		last_expr = ft_zebu_get_curr_tok(factory);
		if (last_expr->id == E_COMPOUND_LIST)
			ilist = last_expr->reduced;
		token_del((t_token**)&last_expr);
	}
	if (!(subshell = new_subshell(ilist)))
		factory->main_status = TF_STATUS_ERROR;
	remove_opexpr(factory->customparam);
	return (subshell);
}
