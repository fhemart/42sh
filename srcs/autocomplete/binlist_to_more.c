/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binlist_to_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 02:41:58 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 10:51:38 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

static int		write_dic_to_fd(t_dictionary *dictionary)
{
	t_word		*curs;
	int			fd;

	fd = open("to_more", O_RDWR | O_TRUNC);
	curs = dictionary->index[0];
	while (curs)
	{
		ft_putendl_fd(curs->word, fd);
		curs = curs->next;
	}
	return (SUCCESS);
}

int				to_more(t_books *books, t_tab *state, t_term *term)
{
	if (state->status == 0)
		write_dic_to_fd(books->all);
	else if (state->status == 1)
	{
		fill_onetime_all(books, books->onetimeall);
		write_dic_to_fd(books->onetimeall);
	}
	term->prompt->beforetab = ft_strcpy(term->prompt->beforetab, \
		ft_dlist_debug_print);
	term->prompt->beforetab = 1;
	ft_control_enter(term->prompt, term);
	return (SUCCESS);
}
