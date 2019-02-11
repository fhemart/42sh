/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_backslash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:22:57 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/05 09:47:01 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

int			tab_backslash(t_tab *state, t_term *term)
{
	(void)term;
	if (state->status == 0)
	{
		state->status = 1;
		state->begin = state->current;
	}
	if (state->quotedmode != '\'')
	{
		state->current++;
		if (state->curs == term->prompt->line->current)
			state->curs = NULL;
		else
			state->curs = state->curs->next;
	}
	return (SUCCESS);
}
