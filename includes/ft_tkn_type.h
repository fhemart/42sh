/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 04:10:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 15:00:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TKN_TYPE_H
# define FT_TKN_TYPE_H

# include "libft.h"

typedef struct s_tkn_factory	t_tkn_factory;
typedef struct s_exptoken		t_exptoken;

typedef struct s_tkn_expr		t_tkn_expr;
typedef struct s_tkn_template	t_tkn_template;
typedef struct s_tkn_grammar	t_tkn_grammar;
typedef struct s_grammar_rule	t_grammar_rule;
typedef union u_blacklist		t_blacklist;

struct		s_tkn_grammar
{
	t_tkn_template	*token_list;
	t_tkn_expr		*expr;
	char			**token_str;
	char			**expr_str;
	t_chrmsk		*token_masks;
	t_chrmsk		*discardmsk;
	t_chrmsk		*quotingmsk;
	t_chrmsk		*wordmsk;
	int				startingexpr;
	int				wordval;
};

# define BLACKLIST_INTSIZE		4
# define BLACKLIST_SIZE			BLACKLIST_INTSIZE * 32

union		u_blacklist
{
	int		mask[BLACKLIST_INTSIZE];
};

/*
**	|-
**	EXPRESSION:
**		value: 		the enumeration state, MUST BE setted with TEXP_VAL()
**		isc:		the internal state count
**		grammar:	the list of possibilities
**						TEXP_GLINE3(WORD, FOO, TEXP_VAL(BAR))
**					this, will activate a sequence of
**					(TOKEN)WORD->(TOKEN)FOO->(EXPR)BAR, and set 7 GLINESTOP
**					in this case, if something else than a FOO token is given
**					when WORD is already set, the factory will
**					generate a syntax error
**	-|
*/

# define EXPR_OFFSET_VAL	(1 << 8)
# define TEXP_VAL(x)		(x | EXPR_OFFSET_VAL)

# define EXPR_ENDOFSTATE	-1
# define EXPR_GLINE_STOP1	EXPR_ENDOFSTATE
# define EXPR_GLINE_STOP2	EXPR_ENDOFSTATE, EXPR_ENDOFSTATE
# define EXPR_GLINE_STOP4	EXPR_GLINE_STOP2, EXPR_GLINE_STOP2
# define EXPR_GLINE_STOP6	EXPR_GLINE_STOP4, EXPR_GLINE_STOP2
# define EXPR_GLINE_STOP8	EXPR_GLINE_STOP4, EXPR_GLINE_STOP4

# define TEXP_GLINE1(x)		{x, EXPR_GLINE_STOP8, EXPR_GLINE_STOP1}
# define TEXP_GLINE2(x)		{x, EXPR_GLINE_STOP8}
# define TEXP_GLINE3(x)		{x, EXPR_GLINE_STOP6, EXPR_GLINE_STOP1}
# define TEXP_GLINE4(x)		{x, EXPR_GLINE_STOP6}
# define TEXP_GLINE5(x)		{x, EXPR_GLINE_STOP4, EXPR_GLINE_STOP1}
# define TEXP_GLINE6(x)		{x, EXPR_GLINE_STOP4}
# define TEXP_GLINE7(x)		{x, EXPR_GLINE_STOP2, EXPR_GLINE_STOP1}
# define TEXP_GLINE8(x)		{x, EXPR_GLINE_STOP2}
# define TEXP_GLINE9(x)		{x, EXPR_GLINE_STOP1}
# define TEXP_EMPTY			TEXP_GLINE9(-1)

# define EXPR_LIST_EMPTY	{0, 0, NULL, NULL, NULL, NULL}
# define TEXP_TEMPLATES(x)	x, EXPR_LIST_EMPTY
# define TEXP_COUNT(x)		x + 1

# define CLEANERCAST(x)		((void(*)(void**))&x)

struct		s_tkn_expr
{
	int			value;
	int			isc;
	int			(*rules)[10];
	char		*tostring;
	void		*(*reducer)(t_tkn_factory*, t_exptoken*);
	void		(*cleaner)(void**);
};

/*
**	|-
**	TEMPLATE:
**		value: 	the enumeration state
**		symbol:	the characters constituing the token
**		size:	the symbol's size
**		cat:	the token operator's category
**	-|
*/

# define TOKEN_LIST_EMPTY	{0, 0, 0, 0}

# define T_TEMPLATES(x)		x, TOKEN_LIST_EMPTY
# define T_COUNT(x)			x + 1

struct		s_tkn_template
{
	int		value;
	char	*symbol;
	size_t	size;
	int		cat;
};

enum		e_token_cat
{
	TT_COMMON = 0,
	TT_OPERATOR_LEFTHANDED = (1 << 0),
	TT_OPERATOR_RIGHTHANDED = (1 << 1),
	TT_OPERATOR_TWOSIDED = (TT_OPERATOR_LEFTHANDED | TT_OPERATOR_RIGHTHANDED)
};

# define TT_CREATE		0
# define TT_DISCARD		1

#endif
