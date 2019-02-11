/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_request.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 12:38:31 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/08 17:58:46 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

int					isdir(const char *path)
{
	struct stat		statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

int					tab_ifdir(t_tab *state, t_term *term, char *word, int bs)
{
	char			path[PATH_MAX];

	ft_strcpy(path, state->path);
	ft_strcat(path, "/");
	ft_strcat(path, word);
	state->writed = 0;
	if (isdir(path) == 1 && bs == 1)
	{
		ft_prompt_printable_key(term->prompt, term, '/');
		term->prompt->tabstop = 1;
		state->writed = 1;
		return (TRUE);
	}
	return (FALSE);
}

void				tab_print_result(int pathlen, t_books *books, \
										t_term *term, t_tab *state)
{
	int				i;
	t_dict_result	*result;

	i = 0;
	result = books->result;
	if (state->status == 1 \
		&& !tab_ifexecbin(state, result->result->word)
		&& pathlen != 0)
		return ;
	if (state->quoted)
		i = (state->current - state->begin) - 1 - pathlen;
	else
		i = (state->current - state->begin) - pathlen;
	term->prompt->hasauto = 1;
	while (result->result->word[i])
		ft_prompt_printable_key(term->prompt, term, \
			(result->result->word)[i++]);
	if (tab_ifdir(state, term, result->result->word, 1) == FALSE \
		&& state->quoted)
		ft_prompt_printable_key(term->prompt, term, state->quotedmode);
	term->prompt->hasauto = 0;
	result->checked++;
	state->writed += ft_strlen(result->result->word);
}

void				write_if_result(int pathlen, t_books *books, t_term *term, \
										t_tab *state)
{
	if (books->result && state->status != 0 && books->result->count == 1)
		tab_print_result(pathlen, books, term, state);
}

int					tab_request(char *word, t_tab *state, t_term *term)
{
	t_books			*books;
	int				pathlen;

	(void)term;
	if (!(books = gsd_books(FT_STGET, NULL, NULL)))
		return (FAILURE);
	if (!(ft_strchrend(word, '/')) && state->status <= 1 && (pathlen = 0) == 0)
	{
		if (state->status == 0)
		{
			if (!books->result && !((books->result = dictionary_new_result())))
				return (FAILURE);
			books->result->result = books->all->indexes[0];
			books->result->count = 0;
		}
		else
			tab_get_regular_binary(books, word, state);
	}
	else
	{
		if ((pathlen = tab_get_unknow(books, word, state, term)) == FAILURE)
			return (FAILURE);
	}
	write_if_result(pathlen, books, term, state);
	return (SUCCESS);
}
