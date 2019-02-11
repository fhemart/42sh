/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_cleanscreentr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:54:43 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:49:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int			ft_prompt_cleanscreentr(t_term *term)
{
	int		i;

	if (PROMPT_DEBUG)
		ft_term_debug_putfd("CLEAN TR MODE");
	i = term->con->size;
	if (term->prompt->line->cursor == term->prompt->promptlen)
	{
		ft_term_writetc(TC_RIGHT);
		i += 1;
	}
	while (--i > -1)
	{
		ft_term_writetc(TC_DELTOENDL);
		ft_term_writetc(TC_DELTOEND);
		ft_term_writetc(TC_LEFT);
	}
	ft_term_writetc(TC_DEL);
	return (TRUE);
}
