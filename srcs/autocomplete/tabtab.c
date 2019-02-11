/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabtab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:18:21 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/08 23:05:55 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int					tabtab(t_books *books, t_tab *state, t_term *term)
{
	int				pp[3];

	fill_onetime_all(books, books->onetime, state);
	ft_dictionary_dbug_printfd(books->onetimeall);
	get_pageprint(term, books, pp);
	print_result_page(books->onetimeall->indexes[0], pp[PP_COL], term, books);
	return (SUCCESS);
}

int					tabtab_isvalide(t_prompt *prompt, t_tab *state)
{
	if (state->begin == state->current)
		return (TRUE);
	else if (prompt->line->current->c == '/')
		return (TRUE);
	else if (prompt->line->current->prev \
			&& prompt->line->current->prev->c == '`' \
			&& state->status == 0)
		return (FALSE);
	else if (state->quotedmode == prompt->line->current->c)
		return (TRUE);
	else if (state->status == 0)
		return (TRUE);
	return (FALSE);
}

int					tab_writeresult(t_books *books, t_term *term, \
								t_dict_result *result)
{
	int				pp[3];

	load_resultinfo(books, result);
	get_pageprint(term, books, pp);
	print_result_page(books->result->result, pp[PP_COL], term, books);
	return (SUCCESS);
}
