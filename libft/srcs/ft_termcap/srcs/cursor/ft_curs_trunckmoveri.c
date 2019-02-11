/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs_trunckmoveri.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:56:04 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:41:09 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"
#include "ft_prompt_private.h"

static void			trunckmoveri_simple(t_term *term)
{
	(void)term;
	ft_term_writetc(TC_RIGHT);
	term->prompt->line->cursor += 1;
	term->trunckmove += 1;
}

static void			trunckmoveri_scroll(t_term *term)
{
	ft_term_writetc(TC_SCROLLDO);
	ft_term_writetc(TC_CARRET);
	term->prompt->line->cursor += 1;
	term->trunckmove += 1;
}

static void			trunckmove_rewrite(t_term *term)
{
	ft_prompt_cleanscreentr(term);
	if (term->scrollcurs == 0)
		term->scrollcurs += 3;
	term->scrollcurs += 1;
	term->nbcharwrite = ft_prompt_wrat2(term, term->scrollcurs);
	term->prompt->line->cursor += 1;
}

int					ft_curs_trunckmoveri(t_term *term, int newpos)
{
	t_line			*line;

	(void)newpos;
	line = term->prompt->line;
	if (term->trunckmove == -1 \
	&& term->scrollcurs + term->nbcharwrite != line->nbelem)
		trunckmove_rewrite(term);
	else if (tr_lastcol_nolastline(line, term))
		trunckmoveri_scroll(term);
	else
		trunckmoveri_simple(term);
	return (TRUE);
}
