/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_compound_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/05 19:38:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

void		*reduce_compound_list(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_exptoken	*term;
	t_inputlist	*ilist;

	(void)expr;
	term = ft_zebu_get_curr_tok(tfactory);
	if (term->id == E_SEPARATOR)
	{
		token_del((t_token**)&term);
		term = ft_zebu_get_curr_tok(tfactory);
	}
	ilist = term->reduced;
	token_del((t_token**)&term);
	if ((term = ft_zebu_look_curr_tok(tfactory)) && term->id == E_NEWLINE_LIST)
	{
		token_del((t_token**)&term);
		term = ft_zebu_get_curr_tok(tfactory);
	}
	return (ilist);
}
