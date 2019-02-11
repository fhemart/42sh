/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_rdlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/07 10:38:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

void				*reduce_rdlist(t_tkn_factory *factory, t_exptoken *expr)
{
	t_exptoken	*last_expr;
	t_iocontent	*first_ioc;
	t_iocontent	*second_ioc;

	last_expr = ft_zebu_get_curr_tok(factory);
	second_ioc = last_expr->reduced;
	token_del((t_token**)&last_expr);
	if (expr->validstate == 1)
	{
		last_expr = ft_zebu_get_curr_tok(factory);
		first_ioc = last_expr->reduced;
		token_del((t_token**)&last_expr);
	}
	else
		first_ioc = NULL;
	ft_lstadd((t_list**)&first_ioc, (t_list*)second_ioc);
	return (first_ioc);
}
