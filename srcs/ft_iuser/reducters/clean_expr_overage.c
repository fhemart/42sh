/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_expr_overage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/06 19:01:03 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_tlex.h"

void		clean_expr_overage(t_tkn_factory *factory, t_exptoken *expr)
{
	t_token	*tmp;

	expr->state = expr->validstate;
	expr->substate = 0;
	while (!substate_match_id(expr, EXPR_ENDOFSTATE))
	{
		tmp = ft_zebu_get_curr_tok(factory);
		token_del(&tmp);
		expr->substate++;
	}
}
