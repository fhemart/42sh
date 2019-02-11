/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_new_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:38:21 by fhemart           #+#    #+#             */
/*   Updated: 2018/08/27 02:57:58 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"

t_word			*dictionary_new_word(char *word)
{
	t_word		*new_word;

	if (!word || !*word)
		return (NULL);
	if (!(new_word = malloc(sizeof(t_word))))
		return (NULL);
	ft_bzero(new_word, sizeof(t_word));
	new_word->len = ft_strlen(word);
	if (!(new_word->word = ft_strdup(word)))
	{
		ft_memdel((void**)new_word);
		return (NULL);
	}
	return (new_word);
}
