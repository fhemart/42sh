/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs_trunckmovele.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:53:45 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:40:00 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

int			ft_curs_trunckmovele(t_term *term, int newpos)
{
	t_line	*line;

	(void)newpos;
	line = term->prompt->line;
	if (term->scrollcurs + term->prompt->promptlen == line->cursor)
	{
		ft_prompt_cleanscreentr(term);
		term->scrollcurs -= 1;
		term->nbcharwrite = ft_prompt_wrat2(term, term->scrollcurs);
		if (line->cursor > 0)
			line->cursor -= 1;
	}
	else if (newpos < line->cursor)
	{
		ft_term_writetc(TC_LEFT);
		line->cursor -= 1;
		term->trunckmove -= 1;
	}
	return (TRUE);
}
