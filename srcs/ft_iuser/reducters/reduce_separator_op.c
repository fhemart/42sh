/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_separator_op.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/05 19:09:59 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

static void		set_listseptype(t_queue *list, int septype)
{
	t_inputlist	*inputlist;

	inputlist = ft_queue_lookfront(list);
	inputlist->septype = septype;
}

void			*reduce_separator_op(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_exptoken	*prev_expr;
	t_token		*septok;

	septok = ft_zebu_get_curr_tok(tfactory);
	token_del(&septok);
	prev_expr = ft_zebu_look_curr_tok(tfactory);
	if (prev_expr->id == E_LIST || prev_expr->id == E_TERM)
		set_listseptype(prev_expr->reduced, expr->validstate);
	return (NULL);
}
