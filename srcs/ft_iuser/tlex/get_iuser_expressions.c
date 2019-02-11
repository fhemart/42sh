/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iuser_expressions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:08:55 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 14:18:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_iuser.h"

t_tkn_template	*get_iuser_tokens(void)
{
	static t_tkn_template	tokens[IUSER_TOKEN_COUNT] = {IUSER_TOKEN_LIST};

	return (tokens);
}

char			**get_iuser_expr_str(void)
{
	static char		*strval[IUSER_EXPR_COUNT] = {IUSER_EXPR_STR};

	return (strval);
}

static t_bool	expr_isset(t_tkn_expr *expr)
{
	if (!expr || !expr->rules)
		return (FALSE);
	return (TRUE);
}

t_tkn_expr		*get_iuser_expressions(void)
{
	static t_tkn_expr	expressions[IUSER_EXPR_COUNT] = {IUSER_EXPR_LIST};
	static int			rules[IUSER_GRAMMAR_SIZE][10] = {IUSER_GRAMMAR_LIST};
	static char			*exptostring[IUSER_EXPR_COUNT] = {IUSER_EXPR_STR};
	int					i;
	int					j;

	if (!expr_isset(expressions))
	{
		i = -1;
		j = 0;
		while (++i < IUSER_EXPR_COUNT - 1)
		{
			expressions[i].rules = &rules[j];
			expressions[i].tostring = exptostring[i];
			j += expressions[i].isc;
		}
	}
	return (expressions);
}
