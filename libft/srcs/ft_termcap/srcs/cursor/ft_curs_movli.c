/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs_movli.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:50:48 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/04 01:19:36 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

int			ft_curs_movli(t_term *term, int currentli, int newli)
{
	t_con	*con;
	t_line	*line;

	con = term->con;
	line = term->prompt->line;
	if (currentli > newli)
	{
		if (line->nbelem > con->size)
		{
			if (newli < line->last->li + 1 - con->li)
				ft_curs_movli_up(currentli, newli, term);
			else
				ft_curs_movli_up(currentli, newli, term);
		}
		else
			ft_curs_movli_up(currentli, newli, term);
	}
	else if (currentli < newli)
		ft_curs_movli_do(currentli, newli, term);
	return (TRUE);
}
