/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_getline_debug.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:32:49 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/08 19:06:38 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			ft_prompt_getline_debug(struct s_line *line, t_term *term)
{
	ft_prompt_debug_putfd_termsize(term->con);
	ft_term_debug_putfd("---- term mode ------");
	ft_term_debug_putfd(ft_static_itoa(term->mode));
	if (line->current)
		ft_prompt_debug_putfd_current(line->current);
	ft_term_debug_putfd("cursor");
	ft_term_debug_putfd(ft_static_itoa(line->cursor));
	ft_term_debug_putfd("nbelem");
	ft_term_debug_putfd(ft_static_itoa(line->nbelem));
	ft_term_debug_putfd("scrollcurs");
	ft_term_debug_putfd(ft_static_itoa(term->scrollcurs));
	ft_term_debug_putfd("trunckmove");
	ft_term_debug_putfd(ft_static_itoa(term->trunckmove));
	ft_term_debug_putfd("nbcharwrite");
	ft_term_debug_putfd(ft_static_itoa(term->nbcharwrite));
	ft_term_debug_putfd("lastkey");
	ft_term_debug_putfd(ft_static_itoa(term->lastkey));
	ft_term_debug_putfd("promplen");
	ft_term_debug_putfd(ft_static_itoa(term->prompt->promptlen));
	ft_term_debug_putfd("---- end ------------\n\n");
}
