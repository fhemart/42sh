/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_haswordba.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:46:16 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 02:15:08 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

static int		check_endworld(char c)
{
	if (c == ' ' \
		|| c == ';' \
		|| c == '&' \
		|| c == '|' \
		|| c == '\'' \
		|| c == '"')
		return (TRUE);
	return (FALSE);
}

int				ft_dlist_haswordba(t_term *term)
{
	t_cell		*curs;
	int			i;
	int			space;

	i = 1;
	space = 0;
	curs = term->prompt->line->current;
	if (!curs)
		return (0);
	while (curs->prev)
	{
		if (curs->skip == FALSE)
		{
			if (curs->prev && curs->c != ' ' \
			&& check_endworld(curs->prev->c) == TRUE && i != 0)
				return (i);
			if (curs->c == ' ')
				space++;
			i++;
		}
		curs = curs->prev;
	}
	if ((space > 0 || curs) && term->prompt->line->head->c != ' ')
		return (i);
	return (0);
}
