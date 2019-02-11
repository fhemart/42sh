/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_moveend.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 04:03:28 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 06:44:50 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

static int			moveend_trunck(t_prompt *prompt, t_term *term)
{
	ft_prompt_clean(term);
	prompt->line->current = prompt->line->last;
	prompt->line->cursor = prompt->promptlen + prompt->line->nbelem;
	term->scrollcurs = prompt->line->cursor - term->prompt->promptlen - 8;
	term->nbcharwrite = ft_prompt_wrat2(term, term->scrollcurs);
	return (TRUE);
}

int					ft_control_moveend(t_prompt *prompt, t_term *term)
{
	t_cell			*curs;
	t_line			*line;

	line = term->prompt->line;
	curs = line->current;
	if (!curs)
		return (FALSE);
	if (term->mode == MODE_TRUNC)
		return (moveend_trunck(prompt, term));
	while (curs != line->last)
	{
		ft_control_right(prompt, term);
		curs = curs->next;
	}
	ft_control_right(prompt, term);
	return (TRUE);
}
