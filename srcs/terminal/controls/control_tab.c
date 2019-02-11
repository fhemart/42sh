/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 22:20:56 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/08 17:53:57 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

static int			get_str_index(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (FAILURE);
}

int					tab_anal(t_prompt *prompt, t_term *term, char c, \
							t_tab *state)
{
	static int		(*fntab[FNT_COUNT])() = {FNT_ALL};
	int				index;

	(void)prompt;
	if (ft_msk_char_match_pattern(c, &state->chrmsk)
	&& (index = get_str_index(FNTAB_STR, c)) != FAILURE)
		return (fntab[index](state, term));
	else if (state->status == 0)
	{
		state->begin = state->current;
		if (prompt->sline_iter > 0)
		{
			state->status = 2;
			return (SUCCESS);
		}
		state->status = 1;
	}
	return (SUCCESS);
}

static int			tab_nani(t_tab *state, t_term *term)
{
	t_books			*books;

	if (!(books = gsd_books(FT_STGET, NULL, NULL)))
		return (FAILURE);
	if (!is_dictionary_result(books))
		ft_dictionary_destroy_result(&books->result);
	books->writed = 0;
	tab_load(state, term);
	return (SUCCESS);
}

static void			tab_debug(t_tab *state)
{
	ft_term_debug_putfd("STATE :");
	ft_term_debug_putfd(ft_static_itoa(state->status));
	ft_term_debug_putfd(ft_static_itoa(state->quoted));
	ft_term_debug_putfd(ft_static_itoa(state->quotedmode));
	ft_term_debug_putfd(ft_static_itoa(state->begin));
	ft_term_debug_putfd(ft_static_itoa(state->current));
	ft_term_debug_putfd("-------\n");
}

int					control_tab(t_prompt *prompt, t_term *term)
{
	static t_tab	state;

	if (term->lastkey == TAB && !prompt->tabstop)
		return (tab_next(prompt, term, &state));
	prompt->tabstop = 0;
	ft_bzero(&state, sizeof(state));
	state.shinfo = &((t_iuser*)prompt->cparam)->shdata->info;
	state.chrmsk = ft_msk_new_chrmsk(FNTAB_STR);
	state.curs = prompt->line->head;
	while (state.curs && state.curs != prompt->line->current->next)
	{
		tab_anal(prompt, term, state.curs->c, &state);
		if (state.curs)
		{
			state.curs = state.curs->next;
			state.current++;
		}
	}
	tab_nani(&state, term);
	if (PROMPT_DEBUG)
		tab_debug(&state);
	return (SUCCESS);
}
