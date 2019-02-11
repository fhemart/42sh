/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_insert_word.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:17:25 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/07 20:23:44 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"
#include "ft_dictionary_private.h"

int			dictionary_insert_word(t_word **newpos, t_word **first, \
											char *word)
{
	if (*newpos == *first && (ft_strcmp((*first)->word, word)) >= 1)
		return (insert_first_word(first, word));
	else
		return (insert_word(newpos, word));
}
