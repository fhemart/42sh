/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_first_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:14:16 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/07 20:23:11 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"
#include "ft_dictionary_private.h"

int			insert_first_word(t_word **first, char *word)
{
	t_word	*new_word;
	t_word	*tmp;

	tmp = *first;
	if (!(new_word = dictionary_new_word(word)))
		return (FAILURE);
	new_word->next = *first;
	*first = new_word;
	return (SUCCESS);
}
