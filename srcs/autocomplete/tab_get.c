/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:39:27 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/09 20:20:32 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

static int		tab_get_word(t_dictionary *dictionary, char *word, \
									t_tab *state)
{
	char		*filename;

	filename = ft_strchrend(word, '/');
	if (state->quoted)
	{
		if (filename)
			return (ft_dictionary_get(dictionary, filename + 1, \
				ft_strlen(filename + 1)));
		else
			return (ft_dictionary_get(dictionary, word, \
				state->current - state->begin - 1));
	}
	else
	{
		if (filename)
			return (ft_dictionary_get(dictionary, filename + 1, \
				ft_strlen(filename + 1)));
		else
			return (ft_dictionary_get(dictionary, word, \
				state->current - state->begin));
	}
}

static char		*parse_tilde(char **path, t_term *term)
{
	char		*tmp;
	t_shdata	*shdata;
	char		*home;
	char		*cooked_path;

	cooked_path = NULL;
	shdata = ((t_iuser*)term->prompt->cparam)->shdata;
	home = shdata->info.home;
	if (!*path)
		*path = ft_strdup(".");
	else if (!home && (*path)[0] == '~')
	{
		ft_strdel(path);
		*path = ft_strdup(" ");
	}
	if ((*path)[0] == '~')
	{
		tmp = ft_strdup(*path + 1);
		if (tmp[0])
			cooked_path = ft_strjoin(shdata->info.home, tmp);
		else
			cooked_path = ft_strdup(shdata->info.home);
		free(tmp);
	}
	return (cooked_path);
}

static int		tab_fill_dico(t_dictionary **dictionary, char *word, \
									t_tab *state, t_term *term)
{
	char		*path;
	char		*cooked_path;
	char		*filename;
	int			pathlen;

	path = NULL;
	cooked_path = NULL;
	filename = NULL;
	pathlen = 0;
	if (ft_dictionary_new(dictionary) == FAILURE)
		return (FAILURE);
	if ((filename = ft_strchrend(word, '/')))
	{
		path = ft_strsub(word, 0, (filename - word == 0) ? 1 : filename - word);
		pathlen = ft_strlen(path) + 1;
		cooked_path = parse_tilde(&path, term);
	}
	if (!path)
		path = ft_strdup(".");
	ft_strcpy(state->path, path);
	ft_memdel((void **)&path);
	tab_browse_unknow(cooked_path, state, dictionary);
	ft_memdel((void **)&cooked_path);
	return (pathlen);
}

void			tab_get_regular_binary(t_books *books, char *word, t_tab *state)
{
	if (tab_get_word(books->builtins, word, state) == TRUE)
		books->result = books->builtins->result;
	else if (tab_get_word(books->bin, word, state) == TRUE)
		books->result = books->bin->result;
	else
		books->result = NULL;
}

int				tab_get_unknow(t_books *books, char *word, t_tab *state, \
									t_term *term)
{
	int			pathlen;
	char		*test;

	pathlen = 0;
	if ((pathlen = tab_fill_dico(&books->onetime, word, \
								state, term)) == FAILURE)
		return (FAILURE);
	test = ft_strchrend(word, '/');
	if (test == word)
		pathlen--;
	if (tab_get_word(books->onetime, word, state) == TRUE)
		books->result = books->onetime->result;
	else
		books->result = NULL;
	return (pathlen);
}
