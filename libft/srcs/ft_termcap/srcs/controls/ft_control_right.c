/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 04:09:10 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 01:45:23 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

int					ft_control_right(t_prompt *prompt, t_term *term)
{
	t_line			*line;

	line = term->prompt->line;
	if (prompt->inbsearch)
		return (ft_prompt_clr_exitbs_upd(prompt, term, FALSE));
	if (line->current \
		&& (line->current != line->last))
	{
		if (line->cursor != term->prompt->promptlen)
			line->current = line->current->next;
		ft_curs_mov(term, line->cursor + 1);
	}
	else if (line->current \
		&& (line->current == line->last)
		&& prompt->line->cursor == prompt->promptlen)
		ft_curs_mov(term, line->cursor + 1);
	if (line->current \
	&& (line->current->c == '\t' || line->current->skip == TRUE) \
	&& line->current->next && line->current->next->skip == TRUE)
		ft_control_right(prompt, term);
	return (TRUE);
}
