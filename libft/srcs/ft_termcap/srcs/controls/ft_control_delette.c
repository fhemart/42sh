/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_delette.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 23:28:18 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/02 18:44:27 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void				delette_trunc(t_prompt *prompt, t_term *term)
{
	t_line			*line;

	line = prompt->line;
	prompt->hasdel = 1;
	if (line->cursor > prompt->promptlen)
	{
		ft_prompt_cleanscreentr(term);
		ft_dlist_rmnode(line, prompt->pool);
		if (line->cursor - prompt->promptlen <= term->scrollcurs + 1\
				&& term->scrollcurs != 0)
		{
			term->nbcharwrite = ft_prompt_wrat2(term, term->scrollcurs - 2);
			term->scrollcurs -= 2;
		}
		else
		{
			term->nbcharwrite = ft_prompt_wrat2(term, term->scrollcurs);
		}
		line->cursor -= 1;
		term->prompt->hasdel = 0;
	}
}

static void			del_if_skip(t_prompt *prompt, t_term *term, char skip)
{
	if (skip == TRUE)
		ft_control_delette(prompt, term);
}

static void			delete_normal(t_prompt *prompt, t_term *term, t_line *line)
{
	ft_curs_mov(term, line->cursor - 1);
	ft_term_writetc(TC_DEL);
	if ((prompt->line->cursor + 1) % term->con->co == 0)
		ft_term_writetc(TC_DELTOEND);
	ft_dlist_rmnode(line, prompt->pool);
}

static void			get_out_trmode(t_prompt *prompt, t_term *term)
{
	t_line			*line;

	line = prompt->line;
	if (line->nbelem + prompt->promptlen < term->con->size - SECU_OFFSET \
		&& term->mode == MODE_TRUNC)
		wrupdate_in_nm(term, prompt);
}

int					ft_control_delette(t_prompt *prompt, t_term *term)
{
	t_line			*line;
	char			skip;

	line = prompt->line;
	skip = line->current ? line->current->skip : FALSE;
	if (line && term->mode == MODE_TRUNC)
		delette_trunc(prompt, term);
	else
	{
		if (line->current)
		{
			if (line->cursor > 0 + term->prompt->promptlen)
				delete_normal(prompt, term, line);
			if (line->current != line->last)
			{
				prompt->hasdel = 1;
				ft_prompt_wratcurrent(term);
				term->prompt->hasdel = 0;
			}
		}
	}
	del_if_skip(prompt, term, skip);
	get_out_trmode(prompt, term);
	return (TRUE);
}
