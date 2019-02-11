/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:16:05 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/07 20:16:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"

int		insert_word(t_word **newpos, char *word)
{
	t_word	*tmp;

	if ((*newpos)->next)
		tmp = (*newpos)->next;
	else
		tmp = NULL;
	if (!((*newpos)->next = dictionary_new_word(word)))
	{
		(*newpos)->next = tmp;
		return (FAILURE);
	}
	(*newpos)->next->next = tmp;
	return (SUCCESS);
}
