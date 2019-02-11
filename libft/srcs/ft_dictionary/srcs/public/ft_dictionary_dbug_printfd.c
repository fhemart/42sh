/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_dbug_printfd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 02:55:55 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/08 15:46:29 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"

static void		dbug_printfd(t_dictionary *dictionary, int i, int debug_fd)
{
	t_word		*curs;

	if (dictionary->indexes[i])
	{
		ft_putstr_fd("LETTER : ", debug_fd);
		ft_putchar_fd(i, debug_fd);
		ft_putchar_fd('\n', debug_fd);
		curs = dictionary->indexes[i];
		ft_putendl_fd(curs->word, debug_fd);
		if (curs->next)
		{
			curs = curs->next;
			while (curs)
			{
				ft_putendl_fd(curs->word, debug_fd);
				curs = curs->next;
			}
		}
		ft_putchar_fd('\n', debug_fd);
	}
}

void			ft_dictionary_dbug_printfd(t_dictionary *dictionary)
{
	const int	oflag = O_APPEND | O_CREAT | O_WRONLY;
	int			i;
	int			debug_fd;

	if (DIC_DEBUG == 0 || (debug_fd = open("debug.log", oflag, 0644)) == -1)
		return ;
	i = 0;
	while (i < 129)
	{
		dbug_printfd(dictionary, i, debug_fd);
		i++;
	}
	close(debug_fd);
}
