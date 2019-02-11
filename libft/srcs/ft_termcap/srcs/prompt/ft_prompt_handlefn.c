/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_handlefn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:24:05 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:55:05 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "controls.h"

static inline t_bool	allowed_bsearch_event(int event)
{
	const int			allowed[BSALLOWED_CNT] = {BSALLOWED};
	int					i;

	i = -1;
	while (++i < BSALLOWED_CNT)
		if (event == allowed[i])
			return (TRUE);
	return (FALSE);
}

int						ft_prompt_handlefn(int event, t_prompt *prompt, \
											t_term *term, t_control *controls)
{
	int					stop;
	int					i;
	int					size;

	i = 0;
	size = term->con->size - SECU_OFFSET;
	stop = controls->nbaction;
	while (i < stop)
	{
		if (controls->key_handle[i] == event)
		{
			if (prompt->line->nbelem + prompt->promptlen > size \
				&& term->mode == MODE_NORMAL)
				ft_prompt_wrupdate(prompt, term);
			if (prompt->inbsearch && allowed_bsearch_event(event) == FALSE)
				return (controls->f[18](prompt, term));
			return (controls->f[i](prompt, term));
		}
		i++;
	}
	return (FAILURE);
}
