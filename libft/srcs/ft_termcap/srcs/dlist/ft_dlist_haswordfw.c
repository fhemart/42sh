/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_haswordfw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:06:50 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/09 19:58:48 by jbulant          ###   ########.fr       */
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

int				ft_dlist_haswordfw(t_term *term)
{
	t_cell		*curs;
	int			i;
	int			j;

	if ((!(curs = term->prompt->line->current)
	|| !(curs = curs->next)))
		return (0);
	i = term->prompt->line->cursor == term->prompt->promptlen ? 1 : 0;
	j = 0;
	while (curs)
	{
		if (!((curs->c == '\t' || curs->skip == TRUE) \
			&& curs->next && curs->next->skip == TRUE))
		{
			if (curs->prev && curs->c != ' ' \
			&& check_endworld(curs->prev->c) == TRUE && i != 0)
				return (i + j);
			i++;
		}
		curs = curs->next;
	}
	return (i);
}
