/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_complete_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/08 14:10:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

void		*reduce_complete_command(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_exptoken	*list;
	t_inputlist	*ilist;

	(void)expr;
	list = ft_zebu_get_curr_tok(tfactory);
	token_del((t_token**)&list);
	list = ft_zebu_get_curr_tok(tfactory);
	if (list->id == E_SEPARATOR_OP)
	{
		token_del((t_token**)&list);
		list = ft_zebu_get_curr_tok(tfactory);
	}
	ilist = list->reduced;
	token_del((t_token**)&list);
	return (ilist);
}
