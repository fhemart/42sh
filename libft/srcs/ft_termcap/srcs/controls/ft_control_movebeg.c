/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_movebeg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 04:02:24 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/12 12:56:13 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

static int			movebeg_trunck(t_prompt *prompt, t_term *term)
{
	ft_prompt_clean(term);
	prompt->line->current = prompt->line->head;
	prompt->line->cursor = prompt->promptlen;
	term->scrollcurs = 0;
	term->nbcharwrite = ft_prompt_wrat2(term, term->scrollcurs);
	return (TRUE);
}

int					ft_control_movebeg(t_prompt *prompt, t_term *term)
{
	t_cell			*curs;
	t_line			*line;

	line = term->prompt->line;
	curs = line->current;
	if (!curs)
		return (FALSE);
	if (term->mode == MODE_TRUNC)
		return (movebeg_trunck(prompt, term));
	while (curs != line->head)
	{
		ft_control_left(prompt, term);
		curs = curs->prev;
	}
	ft_control_left(prompt, term);
	return (TRUE);
}
