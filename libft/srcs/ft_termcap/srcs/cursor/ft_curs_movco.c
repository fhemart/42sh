/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs_movco.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:45:25 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:38:37 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

int					ft_curs_movco(int origin, int newco, t_term *term)
{
	static char		*term_cursor_hpos;
	static char		*sb;
	char			*str;

	if (!term_cursor_hpos)
		term_cursor_hpos = tgetstr("ch", &sb);
	if (newco < origin)
		ft_curs_movco_le(origin, newco, term);
	else
	{
		if (!(str = tgoto(term_cursor_hpos, 0, newco)))
			return (FALSE);
		ft_putstr(tgoto(term_cursor_hpos, 0, newco));
	}
	return (TRUE);
}
