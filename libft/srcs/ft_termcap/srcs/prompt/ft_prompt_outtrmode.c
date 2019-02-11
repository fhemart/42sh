/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_outtrmode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:59:10 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 08:23:25 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int			ft_prompt_outtrmode(t_term *term, int mode)
{
	t_cell	*curs;
	t_line	*line;

	(void)mode;
	line = term->prompt->line;
	curs = line->head;
	ft_prompt_clean(term);
	ft_term_writetc(TC_INTE);
	ft_prompt_clean(term);
	term->mode = 1;
	term->scrollcurs = -1;
	ft_putstr(term->prompt->prompt);
	while (curs)
	{
		ft_prompt_writechar(curs, term, term->prompt);
		curs = curs->next;
	}
	return (TRUE);
}
