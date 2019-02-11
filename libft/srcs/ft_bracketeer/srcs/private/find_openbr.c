/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_openbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:51:31 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/28 20:48:51 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

static void		debug_fopenbr(t_brinfo *match)
{
	if (!match)
		return ;
	ft_putstr("[open_br] : (");
	ft_putnbr(match->size[BRACK_OPEN]);
	ft_putstr(") '");
	ft_putstr(match->op);
	ft_putstr("'\n");
}

void			find_openbr(t_brdata *data)
{
	t_brset		*dummy;
	t_brinfo	*match;
	int			largest_size;

	match = NULL;
	largest_size = 1;
	dummy = data->sets;
	while (dummy)
	{
		if (largest_size <= dummy->info.size[BRACK_OPEN]
		&& ft_strnequ(dummy->info.op, data->src, dummy->info.size[BRACK_OPEN]))
		{
			match = &dummy->info;
			largest_size = match->size[BRACK_OPEN];
		}
		dummy = dummy->next;
	}
	if (match)
		ft_stack_add_content(data->brstack, match);
	if (BRACK_DEBUGPRINT)
		debug_fopenbr(match);
	data->src += largest_size;
}
