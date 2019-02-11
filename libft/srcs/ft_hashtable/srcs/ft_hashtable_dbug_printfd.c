/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_dbug_printfd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 03:00:06 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 03:28:16 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

static void			dbug_printfd(t_hashtable *hashtable, int i, int debug_fd)
{
	t_hashcontent	*curs;

	curs = NULL;
	if ((t_hashcontent*)hashtable->indexes[i])
	{
		ft_putstr_fd("Index : ", debug_fd);
		ft_putstr_fd(ft_static_itoa(i), debug_fd);
		ft_putchar_fd('\n', debug_fd);
		ft_putendl_fd(((t_hashcontent*)hashtable->indexes[i])->name, debug_fd);
		ft_putendl_fd(((t_hashcontent*)hashtable->indexes[i])->fullpath, \
						debug_fd);
		curs = hashtable->indexes[i];
		if (curs->next)
		{
			curs = curs->next;
			while (curs)
			{
				ft_putendl_fd(curs->name, debug_fd);
				ft_putendl_fd(curs->fullpath, debug_fd);
				curs = curs->next;
			}
		}
		ft_putchar_fd('\n', debug_fd);
	}
}

void				ft_hashtable_dbug_printfd(t_hashtable *hashtable)
{
	int				i;
	int				debug_fd;

	i = 0;
	if ((debug_fd = open("debug.log", O_APPEND | O_CREAT | O_WRONLY)) == -1)
		return ;
	while (i < HASHTABLE_SIZE)
	{
		dbug_printfd(hashtable, i, debug_fd);
		i++;
	}
	close(debug_fd);
}
