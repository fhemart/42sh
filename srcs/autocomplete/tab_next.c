/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:38:05 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/08 23:05:34 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

static int			tab_cycle_result(t_dict_result *result, t_books *books, \
								t_term *term, t_tab *state)
{
	t_word			*word;
	size_t			i;
	int				index;
	int				len;

	i = -1;
	len = ft_strlen(state->path);
	if (len == 1 && *state->path == '.' && state->status > 1)
		index = state->current - state->begin;
	else
		index = (state->current - state->begin - len) - (len ? 1 : 0);
	word = books->result->result;
	if (books->writed == 0 && result->count != 1 && term->mode == MODE_NORMAL)
		tab_writeresult(books, term, result);
	if (result->checked < result->count)
	{
		erase_word(books, term, state, index);
		word = get_next_word(word, result);
		print_result(term, word, state, result);
	}
	if (result->checked == result->count)
		result->checked = 0;
	return (SUCCESS);
}

int					tab_next(t_prompt *prompt, t_term *term, t_tab *state)
{
	t_dict_result	*result;
	t_books			*books;

	(void)prompt;
	if (!(books = gsd_books(FT_STGET, NULL, NULL)))
		return (FAILURE);
	result = books->result;
	if (result && result->result && state->status != 0)
		tab_cycle_result(result, books, term, state);
	else if (tabtab_isvalide(prompt, state) && term->mode == MODE_NORMAL)
		tabtab(books, state, term);
	return (SUCCESS);
}
