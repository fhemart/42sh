/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 02:06:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/06 19:06:14 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

int		get_next_token_type(t_tlexicon *tlex, const char *src)
{
	t_tkn_grammar	*grammar;
	t_tkn_template	*token_list;
	int				i;

	grammar = tlex->grammar;
	token_list = grammar->token_list;
	i = -1;
	if (char_match_pattern(*src, grammar->wordmsk))
	{
		token_list = grammar->token_list;
		i = -1;
		while (token_list[++i].symbol)
			if (ft_strnequ(src, token_list[i].symbol, token_list[i].size))
				return (i);
	}
	return (grammar->wordval);
}
