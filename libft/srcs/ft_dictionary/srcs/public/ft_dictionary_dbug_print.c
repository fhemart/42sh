/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_dbug_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:28:11 by fhemart           #+#    #+#             */
/*   Updated: 2018/08/27 02:56:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"

void			ft_dictionary_dbug_print(t_dictionary *dictionary)
{
	int			i;
	t_word		*curs;

	i = 0;
	while (i < 129)
	{
		if (dictionary->indexes[i])
		{
			ft_putchar(i);
			ft_putchar('\n');
			curs = dictionary->indexes[i];
			while (curs)
			{
				ft_putendl(curs->word);
				curs = curs->next;
			}
		}
		i++;
	}
}
