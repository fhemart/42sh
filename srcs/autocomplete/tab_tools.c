/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:23:51 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/09 20:23:15 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

t_bool			is_dictionary_result(t_books *books)
{
	if (books->onetime && books->result == books->onetime->result)
		return (TRUE);
	if (books->onetimeall && books->result == books->onetimeall->result)
		return (TRUE);
	if (books->bin && books->result == books->bin->result)
		return (TRUE);
	if (books->builtins && books->result == books->builtins->result)
		return (TRUE);
	if (books->all && books->result == books->all->result)
		return (TRUE);
	return (FALSE);
}

int				tab_fptr_addbin(char *detail, char *word, \
					t_dictionary *dictionary)
{
	char	file[PATH_MAX];

	ft_strcpy(file, detail);
	if (isdir(file) || is_executable(file, FALSE, NULL, NULL))
		return (ft_dictionary_addword(detail, word, dictionary));
	return (SUCCESS);
}

void			tab_browse_unknow(char *cooked_path, t_tab *state, \
									t_dictionary **dictionary)
{
	ft_browse_dir((cooked_path) ? cooked_path : state->path, \
	(state->status < 2) ? tab_fptr_addbin : ft_dictionary_addword, \
	*dictionary, NULL);
}
