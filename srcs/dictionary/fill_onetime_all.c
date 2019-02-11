/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_onetime_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 05:27:09 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/09 20:04:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "books.h"

static int		fill_all_addword(t_books *books, t_dictionary *dictionary, \
								int i)
{
	t_word		*curs;

	if (dictionary->indexes[i])
	{
		curs = dictionary->indexes[i];
		ft_dictionary_addword_ni(NULL, curs->word, books->onetimeall);
		books->allcount++;
		if (curs->len > (size_t)books->allmaxlen)
			books->allmaxlen = curs->len;
		if (curs->next)
		{
			curs = curs->next;
			while (curs)
			{
				ft_dictionary_addword_ni(NULL, curs->word, books->onetimeall);
				if (curs->len > (size_t)books->allmaxlen)
					books->allmaxlen = curs->len;
				books->allcount++;
				curs = curs->next;
			}
		}
	}
	return (SUCCESS);
}

static int		onetime_parse_argument(t_books *books, t_dictionary *onetime, \
									t_tab *state)
{
	int			i;

	(void)onetime;
	i = 0;
	while (i < 129)
	{
		if (state->begin == state->current)
		{
			if (tab_request("", state, NULL) == FAILURE)
				return (FAILURE);
		}
		if (fill_all_addword(books, books->onetime, i) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int		onetime_parse_bin(t_books *books, t_dictionary *onetime, \
									t_tab *state)
{
	int			i;

	i = 0;
	while (i < 129)
	{
		if (state->status == 0)
		{
			if (fill_all_addbin(books, books->all, i, state) == FAILURE)
				return (FAILURE);
		}
		else if (fill_all_addbin(books, onetime, i, state) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int				fill_onetime_all(t_books *books, t_dictionary *onetime, \
									t_tab *state)
{
	int			i;

	i = 0;
	books->allmaxlen = 0;
	books->allcount = 0;
	ft_dictionary_destroy(&books->onetimeall);
	if (ft_dictionary_new(&books->onetimeall) == FAILURE)
		return (FAILURE);
	if (state->status == 2)
	{
		if (onetime_parse_argument(books, onetime, state) == FAILURE)
			return (FAILURE);
	}
	else
	{
		if (onetime_parse_bin(books, onetime, state) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
