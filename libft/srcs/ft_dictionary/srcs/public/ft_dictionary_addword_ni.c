/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_addword_ni.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:11:47 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 02:45:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"
#include "ft_dictionary_private.h"

int			ft_dictionary_addword_ni(char *detail, char *word, \
				t_dictionary *dictionary)
{
	int		index;
	t_word	*newpos;

	(void)detail;
	newpos = NULL;
	if (!dictionary || !word)
		return (FAILURE);
	index = 0;
	if (dictionary->indexes[index])
	{
		if (!(newpos = dictionary_get_newpos(&dictionary->indexes[index], word,\
				ft_strcmp)))
			return (FAILURE);
		if ((dictionary_insert_word(&newpos, &dictionary->indexes[index], \
				word)) == FAILURE)
			return (FAILURE);
	}
	else if (!(dictionary->indexes[index] = dictionary_new_word(word)))
		return (FAILURE);
	return (SUCCESS);
}
