/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs_trunckmove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:58:56 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/04 01:19:46 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

int			ft_curs_trunckmove(t_term *term, int newpos)
{
	int		cursor;

	(void)newpos;
	cursor = term->prompt->line->cursor;
	if (newpos < cursor)
		ft_curs_trunckmovele(term, newpos);
	else if (newpos > cursor)
		ft_curs_trunckmoveri(term, newpos);
	return (TRUE);
}
