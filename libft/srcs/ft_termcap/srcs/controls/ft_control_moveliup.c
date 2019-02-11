/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_moveliup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 03:58:54 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/04 17:08:37 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int					ft_control_moveliup(t_prompt *prompt, t_term *term)
{
	int				next_curs;
	t_line			*line;

	line = term->prompt->line;
	next_curs = line->cursor - term->con->co;
	if (line->last && line->last->li == 0)
		return (0);
	while (line->cursor > next_curs && line->cursor > prompt->promptlen)
		ft_control_left(prompt, term);
	return (TRUE);
}
