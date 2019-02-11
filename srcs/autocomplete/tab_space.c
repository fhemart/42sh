/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 23:52:00 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 11:01:04 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

static int			ft_tab_q_space(t_tab *state)
{
	if (state->status == 0)
		state->status = 1;
	return (SUCCESS);
}

static int			ft_tab_nq_space(t_tab *state)
{
	if (state->status != 0)
	{
		state->status = 2;
		state->begin = state->current + 1;
	}
	return (SUCCESS);
}

int					tab_space(t_tab *state, t_term *term)
{
	(void)term;
	if (state->quoted == 0)
		return (ft_tab_nq_space(state));
	else
		return (ft_tab_q_space(state));
}
