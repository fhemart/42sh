/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_all_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:21:23 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/08 23:06:03 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

static int		addbin_ifexec(t_word *curs, t_tab *state, t_books *books)
{
	if (tab_ifexecbin(state, curs->word) == TRUE)
	{
		ft_dictionary_addword_ni(NULL, curs->word, books->onetimeall);
		books->allcount++;
		if (curs->len > (size_t)books->allmaxlen)
			books->allmaxlen = curs->len;
	}
	return (SUCCESS);
}

static int		addbin(t_word *curs, t_tab *state, t_books *books)
{
	(void)state;
	ft_dictionary_addword_ni(NULL, curs->word, books->onetimeall);
	books->allcount++;
	if (curs->len > (size_t)books->allmaxlen)
		books->allmaxlen = curs->len;
	return (SUCCESS);
}

int				fill_all_addbin(t_books *books, t_dictionary *dictionary, \
								int i, t_tab *state)
{
	t_word		*curs;

	if (dictionary->indexes[i])
	{
		curs = dictionary->indexes[i];
		if (state->status == 0)
			addbin(curs, state, books);
		else
			addbin_ifexec(curs, state, books);
		if (curs->next)
		{
			curs = curs->next;
			while (curs)
			{
				if (state->status == 0)
					addbin(curs, state, books);
				else
					addbin_ifexec(curs, state, books);
				curs = curs->next;
			}
		}
	}
	return (SUCCESS);
}
