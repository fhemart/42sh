/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 23:58:50 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 10:53:23 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

static int			quotenext_escape(t_term *term, t_tab *state, t_cell *curs, \
										int *i)
{
	t_cell			*current;

	current = term->prompt->line->current;
	if (curs->next)
	{
		if (curs->next == current)
			curs = NULL;
		else if (curs == current)
		{
			state->curs = NULL;
			state->current += *i + 1;
			curs = NULL;
		}
		else
			curs = curs->next->next;
		*i += 2;
	}
	return (SUCCESS);
}

static int			quotenext_end(t_tab *state, t_cell *curs, int i)
{
	if (state->status == 0)
	{
		state->status = 1;
		state->begin = state->current;
	}
	state->current += i;
	state->curs = curs->prev;
	state->quotedmode = 0;
	return (SUCCESS);
}

static int			tab_quotenext(t_tab *state, t_term *term)
{
	t_cell	*curs;
	int		i;
	char	quote;

	i = 0;
	quote = state->curs->c;
	curs = state->curs->next;
	while (curs && curs != term->prompt->line->current->next)
	{
		if (curs->c == 92 && quote != '\'')
			quotenext_escape(term, state, curs, &i);
		if (curs && curs->c == quote)
		{
			quotenext_end(state, curs, i);
			return (SUCCESS);
		}
		i++;
		if (curs)
			curs = curs->next;
	}
	state->quotedmode = quote;
	return (SUCCESS);
}

int					tab_quote(t_tab *state, t_term *term)
{
	if (state->quotedmode == 0)
		state->quoted++;
	if (state->status != 0 && state->quoted == 1 && state->quotedmode == 0)
	{
		state->status = 2;
		state->begin = state->current;
	}
	if (state->quoted == 1)
	{
		if (state->status == 0)
		{
			state->status = 1;
			state->begin = state->current;
		}
		if (state->quotedmode == 0)
			tab_quotenext(state, term);
	}
	else
		state->quoted = 0;
	return (SUCCESS);
}
