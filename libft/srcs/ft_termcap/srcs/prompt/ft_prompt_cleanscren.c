/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_cleanscren.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:54:05 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/22 18:59:04 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int			ft_prompt_cleanscren(t_term *term)
{
	int		i;

	i = term->prompt->line->cursor + term->prompt->promptlen + 1;
	if (PROMPT_DEBUG)
		ft_term_debug_putfd("CLEAN NM MODE");
	while (--i > -1)
	{
		ft_term_writetc(TC_DELTOENDL);
		ft_term_writetc(TC_DELTOEND);
		ft_term_writetc(TC_LEFT);
	}
	ft_term_writetc(TC_DEL);
	return (TRUE);
}
