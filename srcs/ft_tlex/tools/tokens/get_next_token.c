/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:21:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/07 10:38:53 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

t_token	*get_next_token(t_tlexicon *tlex)
{
	t_tkn_grammar	*grammar;
	t_token			*tkn;
	t_chrmsk		*discardmsk;
	int				next_toktype;

	grammar = tlex->grammar;
	discardmsk = grammar->discardmsk;
	while (tlex->src && *tlex->src
		&& char_match_pattern(*tlex->src, discardmsk))
		tlex->src++;
	if (!tlex->src || !*tlex->src)
	{
		tlex->main_status = TF_STATUS_END;
		return (NULL);
	}
	next_toktype = get_next_token_type(tlex, tlex->src);
	if (next_toktype == ft_tlex_gword(tlex))
		return (create_word(tlex));
	if (!(tkn = create_new_token(NULL, 0, next_toktype)))
		tlex->main_status = TF_STATUS_ERROR;
	else
		tlex->src += grammar->token_list[tkn->type].size;
	return (tkn);
}
