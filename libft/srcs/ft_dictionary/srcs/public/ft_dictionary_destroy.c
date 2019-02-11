/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:38:47 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/02 15:00:05 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"

static int			dictionary_destroy_word(t_word **word)
{
	t_word			*dummy;
	t_word			*next;

	if (!word || !*word)
		return (FAILURE);
	dummy = *word;
	while (dummy)
	{
		next = dummy->next;
		ft_strdel(&dummy->word);
		free(dummy);
		dummy = next;
	}
	*word = NULL;
	return (SUCCESS);
}

int					ft_dictionary_destroy(t_dictionary **dictionary)
{
	int				i;

	i = 0;
	if (!dictionary || !*dictionary)
		return (FAILURE);
	while (i < 128)
	{
		if ((*dictionary)->indexes[i])
			dictionary_destroy_word(&(*dictionary)->indexes[i]);
		i++;
	}
	ft_dictionary_destroy_result(&(*dictionary)->result);
	ft_memdel((void**)dictionary);
	return (SUCCESS);
}
