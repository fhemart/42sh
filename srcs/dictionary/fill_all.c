/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 19:57:43 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 11:48:30 by fhemart          ###   ########.fr       */
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
		books->allmaxlen = 0;
		ft_dictionary_addword_ni(NULL, curs->word, books->all);
		books->allcount = 1;
		if (curs->len > (size_t)books->allmaxlen)
			books->allmaxlen = curs->len;
		if (curs->next)
		{
			curs = curs->next;
			while (curs)
			{
				ft_dictionary_addword_ni(NULL, curs->word, books->all);
				if (curs->len > (size_t)books->allmaxlen)
					books->allmaxlen = curs->len;
				curs = curs->next;
				books->allcount++;
			}
		}
	}
	return (SUCCESS);
}

int				fill_all(t_books *books, t_dictionary *bin, \
						t_dictionary *builtin)
{
	int			i;

	i = 0;
	if ((ft_dictionary_new((t_dictionary**)&books->all)) == FAILURE)
		return (FAILURE);
	while (i < 129)
	{
		if (fill_all_addword(books, builtin, i) == FAILURE)
			return (FAILURE);
		i++;
	}
	i = 0;
	while (i < 129)
	{
		if (fill_all_addword(books, bin, i) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
