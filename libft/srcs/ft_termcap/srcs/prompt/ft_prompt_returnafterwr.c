/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_returnafterwr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:57:40 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/04 01:39:05 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int			ft_prompt_returnafterwr(t_term *term)
{
	t_cell	*curs;
	t_cell	*ref;

	ref = term->prompt->line->current;
	curs = term->prompt->line->last;
	while (curs && curs != ref)
	{
		ft_term_writetc(TC_LEFT);
		if (curs->prev)
			curs = curs->prev;
		else
			curs = NULL;
	}
	return (TRUE);
}
