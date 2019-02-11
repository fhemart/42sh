/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_checkwrite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 08:54:13 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 08:54:45 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int			if_print_in_nm(t_term *term, t_prompt *prompt)
{
	int		size;
	int		cursortoprint;

	size = term->con->size - SECU_OFFSET;
	cursortoprint = prompt->line->nbelem + prompt->promptlen + 1;
	return ((term->mode == MODE_NORMAL && cursortoprint < size));
}

int			if_print_in_tr(t_term *term)
{
	int		size;
	int		cursortoprint;

	size = term->con->size - SECU_OFFSET;
	cursortoprint = term->nbcharwrite + 1;
	return (term->mode == MODE_NORMAL \
		|| (term->mode == MODE_TRUNC && cursortoprint > size));
}

int			if_wrupdate_in_tr(t_term *term, t_prompt *prompt)
{
	int		size;
	int		cursortoprint;

	size = term->con->size - SECU_OFFSET;
	cursortoprint = prompt->line->nbelem + prompt->promptlen;
	return (term->mode == MODE_NORMAL \
		|| (term->mode == MODE_TRUNC && cursortoprint > size));
}

int			if_wrupdate_in_nm(t_term *term, t_prompt *prompt)
{
	int		size;
	int		cursortoprint;

	size = term->con->size - SECU_OFFSET;
	cursortoprint = prompt->line->nbelem + prompt->promptlen;
	return ((term->mode == MODE_NORMAL && cursortoprint < size));
}
