/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_movelido.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 04:00:09 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/04 17:07:03 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int					ft_control_movelido(t_prompt *prompt, t_term *term)
{
	int				next_curs;
	t_line			*line;

	line = term->prompt->line;
	next_curs = line->cursor + term->con->co;
	if (!line->current)
		return (TRUE);
	while (line->cursor < next_curs && line->current->next)
		ft_control_right(prompt, term);
	return (TRUE);
}
