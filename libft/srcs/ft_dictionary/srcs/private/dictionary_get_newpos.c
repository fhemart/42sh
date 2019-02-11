/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_get_newpos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:19:09 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/07 20:23:30 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"
#include "ft_dictionary_private.h"

t_word			*dictionary_get_newpos(t_word **first_word, \
					char *word, int (*cmp)(const char*, const char*))
{
	t_word		*newpos;
	t_word		*prev;
	int			cmpret;

	cmpret = 0;
	newpos = *first_word;
	prev = *first_word;
	while (newpos)
	{
		cmpret = cmp(newpos->word, word);
		if (cmpret == 0)
			return (NULL);
		else if (cmpret >= 1)
			return (prev);
		prev = newpos;
		newpos = newpos->next;
	}
	return (prev);
}
