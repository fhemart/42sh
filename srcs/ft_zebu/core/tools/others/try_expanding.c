/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_expanding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:15:13 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 13:57:52 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_bool			try_expanding(t_tkn_factory *factory, t_exptoken *expr, int id)
{
	t_exptoken	*new;

	if (expr->id == id)
	{
		expr->isrecursive = TRUE;
		return (FALSE);
	}
	if (id == EXPR_ENDOFSTATE)
		return (FALSE);
	if (expr_is_blacklisted(&factory->expr_blacklist, id)
	|| !(new = new_exptoken(id, get_expmodel(factory->grammar, id))))
		return (FALSE);
	new->tsoffset = expr->tsoffset + expr->substate;
	ft_stack_add_content(factory->expressions, new);
	return (TRUE);
}
