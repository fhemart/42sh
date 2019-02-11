/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_ifresise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:26:07 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:55:33 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void				ft_prompt_ifresise(t_term *term)
{
	t_cell			*curs;
	int				li;
	int				co;
	int				limit;

	li = 0;
	co = term->prompt->promptlen;
	limit = term->con->co;
	if (co >= limit)
	{
		li = co / limit;
		co = co % limit;
	}
	curs = term->prompt->line->head;
	while (curs)
	{
		if (co >= limit)
		{
			li++;
			co = 0;
		}
		curs->co = co++;
		curs->li = li;
		curs = curs->next;
	}
}
