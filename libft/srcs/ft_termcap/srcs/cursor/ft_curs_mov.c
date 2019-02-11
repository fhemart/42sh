/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs_mov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 22:19:50 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:36:36 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

int			ft_curs_mov(t_term *term, int newpos)
{
	int		newco;
	int		newli;
	int		currentli;
	int		consoleco;
	t_line	*line;

	consoleco = term->con->co;
	line = term->prompt->line;
	newco = newpos % consoleco;
	newli = newpos / consoleco;
	currentli = line->cursor / consoleco;
	if (term->mode == MODE_TRUNC)
		return (ft_curs_trunckmove(term, newpos));
	else if (currentli != newli)
		ft_curs_movli(term, currentli, newli);
	ft_curs_movco(line->current->co, newco, term);
	line->cursor = newpos;
	line->lastmove = CURSMOVE_MANUAL;
	return (TRUE);
}
