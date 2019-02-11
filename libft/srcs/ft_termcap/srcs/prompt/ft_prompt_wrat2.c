/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_wrat2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 23:07:33 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 08:36:40 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

static int			ft_wrchunck_prefix(int pos)
{
	if (pos != 0)
	{
		ft_putstr("...");
		return (3);
	}
	else
		return (0);
}

static int			ft_wrchunck_getsize(int start, int consize, int nbelem)
{
	int				i;

	i = 0;
	i += ft_wrchunck_prefix(start);
	if (start + consize - i - 4 < nbelem)
		i += 3;
	return (i);
}

int					ft_prompt_wrat2(t_term *term, int pos)
{
	t_cell			*curs;
	int				i;
	int				max;
	t_line			*line;

	i = 0;
	line = term->prompt->line;
	max = (term->con->size - term->prompt->promptlen - SECU_OFFSET);
	curs = line->head;
	max -= ft_wrchunck_getsize(pos, max, line->nbelem);
	i += ft_prompt_wrchunck(term, pos, max);
	ft_prompt_ifresise(term);
	return (i);
}
