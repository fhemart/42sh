/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wordcontent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 02:06:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/05 19:45:01 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

t_lstr	*get_wordcontent(t_tlexicon *tlex, t_tkn_grammar *grammar)
{
	t_lstr		*str;
	char		*tmp;
	int			wval;

	wval = ft_tlex_gword(tlex);
	str = NULL;
	tmp = tlex->src;
	while (*tmp && !char_match_pattern(*tmp, grammar->discardmsk)
	&& get_next_token_type(tlex, tmp) == wval)
	{
		if (char_match_pattern(*tmp, grammar->quotingmsk)
		&& is_openbr(tlex->quote_data, tmp))
		{
			str = reduce_word(&tlex->src, str, (int)(tmp - tlex->src));
			if (extend2qword(tlex, &str) == -1)
				return (NULL);
			else if (!(tmp = tlex->src))
				return (str);
		}
		else
			tmp++;
	}
	str = reduce_word(&tlex->src, str, (int)(tmp - tlex->src));
	return (str);
}
