/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_debug_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:12:34 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/04 16:25:55 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

char			*ft_dlist_debug_print(t_line *root)
{
	static char	buff[PATH_MAX];
	t_cell		*curs;
	int			i;

	i = 0;
	curs = root->head;
	while (curs && i < PATH_MAX - 1)
	{
		buff[i++] = curs->c;
		curs = curs->next;
	}
	buff[i] = '\0';
	return (buff);
}
