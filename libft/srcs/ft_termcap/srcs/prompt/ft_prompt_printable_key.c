/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_printable_key.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 21:08:19 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/02 16:55:23 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"
#include "ftsh.h"

static void				ft_prompt_printkey(char *tmp, t_term *term)
{
	int					hasauto;
	int					scrollcurs;
	t_line				*line;

	(void)tmp;
	line = term->prompt->line;
	hasauto = term->prompt->hasauto;
	scrollcurs = 0;
	if (if_print_in_nm(term, term->prompt))
		ft_prompt_writechar(term->prompt->line->current, term, term->prompt);
	else
	{
		term->prompt->hasinsert = (line->current != line->last) ? 1 : 0;
		if (if_print_in_tr(term))
			printkey_in_tr(scrollcurs, hasauto, term, term->prompt);
		else
			ft_prompt_writechar(term->prompt->line->current, term, \
				term->prompt);
		term->nbcharwrite += 1;
	}
}

static int				is_curent_last_column(t_cell *current, t_term *term)
{
	(void)current;
	if (term->mode == MODE_TRUNC)
		return (0);
	else if ((term->prompt->line->cursor + 1) % term->con->co == 0 \
			&& term->mode == MODE_NORMAL)
		return (1);
	return (0);
}

static void				affect_cursor_current(t_line *line, t_term *term)
{
	if (is_curent_last_column(line->current, term))
	{
		write(0, " ", 1);
		ft_term_writetc(TC_LEFT);
		line->cursor += 1;
	}
	else
	{
		line->cursor += 1;
		line->lastmove = CURSMOVE_AUTO;
	}
}

static void				affect_endofline(t_line *line, t_term *term)
{
	if (line->current != line->last)
	{
		term->prompt->hasinsert = 1;
		if (line->nbelem + term->prompt->promptlen \
				>= term->con->size - SECU_OFFSET)
			term->nbcharwrite = write_ins_truncated(line, term);
		else
			ft_prompt_wratcurrent(term);
		term->prompt->hasinsert = 0;
	}
}

int						ft_prompt_printable_key(t_prompt *prompt, t_term *term,\
											char key)
{
	char				tmp[2];

	if (prompt->inbsearch)
		return (print_in_bsearch(prompt, term, key));
	tmp[1] = '\0';
	tmp[0] = key;
	ft_dlist_addnode(prompt->line, key, prompt->pool);
	ft_prompt_printkey(tmp, term);
	affect_cursor_current(prompt->line, term);
	affect_endofline(prompt->line, term);
	ft_prompt_ifresise(term);
	return (SUCCESS);
}
