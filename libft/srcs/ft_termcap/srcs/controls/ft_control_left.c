/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 04:07:54 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 02:11:04 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

int					ft_control_left(t_prompt *prompt, t_term *term)
{
	t_line			*line;
	int				skip;

	line = term->prompt->line;
	if (prompt->inbsearch)
		return (ft_prompt_clr_exitbs_upd(prompt, term, FALSE));
	skip = line->current ? line->current->skip : FALSE;
	if (line->current \
		&& (line->current != line->head))
	{
		if (ft_curs_mov(term, line->cursor - 1) == 1)
			line->current = line->current->prev;
	}
	else if (line->current \
		&& line->cursor - prompt->promptlen == 1)
		ft_curs_mov(term, line->cursor - 1);
	if (skip == TRUE)
		ft_control_left(prompt, term);
	return (TRUE);
}
