/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_backtick.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:03:01 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 10:52:09 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

int			tab_backtick(t_tab *state, t_term *term)
{
	(void)term;
	if (state->quotedmode != 0)
		return (SUCCESS);
	state->count_backtick++;
	if (state->count_backtick % 2)
		state->status = 0;
	else
	{
		state->status = 2;
	}
	return (SUCCESS);
}
