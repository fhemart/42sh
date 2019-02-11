/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_wratcurrent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:33:05 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/07 02:47:50 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

static int			wratcurrent_wrline(int i, t_term *term)
{
	t_cell			*curs;

	if (!term->prompt->line->current)
		return (0);
	curs = term->prompt->line->current->next;
	if (term->prompt->hasdel \
		&& term->prompt->line->cursor == term->prompt->promptlen)
		curs = term->prompt->line->current;
	while (curs)
	{
		ft_prompt_writechar(curs, term, term->prompt);
		curs = curs->next;
		i++;
	}
	return (i);
}

static int			check_last_co(t_term *term)
{
	(void)term;
	if (term->prompt->line->last->co + 1 % term->con->co == term->con->co)
		return (1);
	return (0);
}

int					ft_prompt_wratcurrent(t_term *term)
{
	int				i;
	int				nbret;

	i = 0;
	if (term->prompt->hasdel)
		ft_term_writetc(TC_DELTOEND);
	i = wratcurrent_wrline(i, term);
	ft_prompt_ifresise(term);
	i -= check_last_co(term);
	nbret = i;
	while (i)
	{
		ft_term_writetc(TC_LEFT);
		i--;
	}
	ft_prompt_ifresise(term);
	return (nbret);
}
