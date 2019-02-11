/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlex_fill_cmpchk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/06 11:53:59 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

void			ft_tlex_fill_cmpchk(t_tlexicon *tlex)
{
	t_tkn_grammar	*grammar;
	t_wordpolish	*wpolish;
	t_token			*curr_tok;
	t_token			*prev_tok;

	grammar = tlex->grammar;
	wpolish = tlex->wpolish;
	prev_tok = (t_token*)ft_queue_lookfront(tlex->tokens);
	while ((curr_tok = get_next_token(tlex)))
	{
		ft_queue_add(tlex->tokens, curr_tok);
		if (!token_are_compatible(prev_tok, curr_tok, grammar->token_list)
		|| (use_word_polish(tlex, curr_tok, wpolish) == -1))
		{
			ft_tlex_errtok(tlex);
			break ;
		}
		prev_tok = curr_tok;
	}
	if (!curr_tok)
		look_last_compatibility(prev_tok, tlex, grammar->token_list);
}
