/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_semico.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:21:43 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/16 18:43:53 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

int			tab_semico(t_tab *state, t_term *term)
{
	(void)term;
	if (state->quotedmode == 0)
		state->status = 0;
	return (SUCCESS);
}

int			tab_epersand(t_tab *state, t_term *term)
{
	(void)term;
	if (state->quotedmode == 0
		&& state->curs->prev
		&& (state->curs->prev->c == '<' || state->curs->prev->c == '>'))
	{
		state->status = 2;
		state->begin = state->current + 1;
	}
	else if (state->quotedmode == 0)
		state->status = 0;
	return (SUCCESS);
}
