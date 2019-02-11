/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_wratchunck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 03:00:06 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 08:52:14 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

static int			ft_wrchunck_sufix(t_term *term, t_cell *curs)
{
	int				i;

	(void)term;
	if (curs)
	{
		ft_putstr("...");
		ft_term_writetc(TC_DELTOENDL);
		i = -1;
		while (++i < 3)
			ft_term_writetc(TC_LEFT);
		return (1);
	}
	return (0);
}

static int			ft_prompt_cursrepos_loop(t_term *term, t_cell *curs, \
												t_cell *current, t_cell *stop)
{
	int				i;

	i = 0;
	if (curs == current)
		return (0);
	else if (curs == current->next)
	{
		ft_term_writetc(TC_LEFT);
		return (-1);
	}
	while (curs && curs != stop)
	{
		ft_term_writetc(TC_LEFT);
		curs = curs->prev;
		i--;
	}
	if (term->prompt->hasdel && \
		term->prompt->line->cursor - 1 == term->prompt->promptlen)
	{
		ft_term_writetc(TC_LEFT);
		i -= 1;
	}
	return (i);
}

static int			ft_prompt_cursrepos(t_term *term, t_cell *lastwr)
{
	int				i;
	t_cell			*curs;
	t_cell			*current;
	t_cell			*stop;

	i = 0;
	curs = lastwr;
	current = term->prompt->line->current;
	stop = (term->prompt->hasdel || term->prompt->hasinsert)\
		? current : current->prev;
	i = ft_prompt_cursrepos_loop(term, curs, current, stop);
	return (i);
}

static void			write_space(t_term *term, int i)
{
	if ((i + 3) % term->con->co == 0)
	{
		ft_putchar(' ');
		ft_term_writetc(TC_LEFT);
	}
}

int					ft_prompt_wrchunck(t_term *term, int start, int size)
{
	t_cell			*curs;
	t_cell			*lastcurs;
	int				i;

	i = 0;
	curs = term->prompt->line->head;
	lastcurs = curs;
	while (curs && i < size)
	{
		if (start <= 0)
		{
			ft_prompt_writechar(curs, term, term->prompt);
			i++;
		}
		lastcurs = curs;
		curs = curs->next;
		start--;
	}
	write_space(term, i);
	ft_wrchunck_sufix(term, curs);
	term->trunckmove = ft_prompt_cursrepos(term, lastcurs);
	return (i);
}
