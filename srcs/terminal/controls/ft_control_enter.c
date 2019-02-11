/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_enter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 03:54:13 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/02 18:46:46 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "brackets.h"
#include "ft_prompt_private.h"

void				go_to_endline(t_prompt *prompt, t_term *term, t_line *line)
{
	t_cell			*curs;

	curs = line->current;
	while (curs)
	{
		ft_control_right(prompt, term);
		curs = curs->next;
	}
}

int					ft_control_enter(t_prompt *prompt, t_term *term)
{
	int				i;
	t_line			*line;

	line = prompt->line;
	i = line->nbelem + prompt->promptlen;
	if (term->mode == 2)
		ft_prompt_outtrmode(term, 0);
	else
	{
		if (prompt->inbsearch)
			ft_prompt_clr_exitbs_upd(prompt, term, FALSE);
		go_to_endline(prompt, term, line);
	}
	write(1, "\n\r", 2);
	line->current = line->last;
	ft_dlist_addnode(line, '\n', prompt->pool);
	prompt->done = 1;
	return (TRUE);
}
