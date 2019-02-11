/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iuser_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:08:55 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 14:18:46 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_iuser.h"

char			*get_token_strvalue(int value)
{
	static char		*strval[IUSER_T_COUNT_NAME] = {TKN_STRVAL};

	if (value >= IUSER_TOKEN_COUNT)
		value = IUSER_TOKEN_COUNT - 1;
	return (strval[value]);
}

static char		**get_iuser_token_str(void)
{
	static char		*strval[IUSER_T_COUNT_NAME] = {TKN_STRVAL};

	return (strval);
}

void			iuser_grammardel(t_tkn_grammar **grammar)
{
	if (!grammar || !*grammar)
		return ;
	free((*grammar)->token_masks);
	free(*grammar);
	*grammar = NULL;
}

t_chrmsk		*get_iuser_chrmsk(void)
{
	static char	*masks[IUSER_MASK_COUNT] = {IUSER_TOKEN_MASK};
	t_chrmsk	*ret;
	size_t		size;

	size = IUSER_MASK_COUNT;
	if (!(ret = (t_chrmsk*)ft_memalloc(sizeof(t_chrmsk) * size)))
		return (NULL);
	while (size--)
		ret[size] = new_chrmsk(masks[size]);
	return (ret);
}

t_tkn_grammar	*get_iuser_grammar(int gsd)
{
	static t_tkn_grammar	*grammar = NULL;

	if (gsd == FT_STGET)
	{
		if (!grammar)
		{
			if (!(grammar = ft_memalloc(sizeof(t_tkn_grammar))))
				return (NULL);
			grammar->expr = get_iuser_expressions();
			grammar->startingexpr = IUSER_STARTING_EXPR;
			grammar->token_list = get_iuser_tokens();
			grammar->token_str = get_iuser_token_str();
			grammar->expr_str = get_iuser_expr_str();
			grammar->token_masks = get_iuser_chrmsk();
			grammar->wordmsk = grammar->token_masks + IUSER_STARTING_WMASK;
			grammar->quotingmsk = grammar->token_masks + IUSER_STARTING_WMASK;
			grammar->quotingmsk++;
			grammar->discardmsk = grammar->token_masks + IUSER_STARTING_DMASK;
			grammar->wordval = TWORD;
		}
	}
	else if (gsd == FT_STDEL)
		iuser_grammardel(&grammar);
	return (grammar);
}
