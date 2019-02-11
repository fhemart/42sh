/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_fnselector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:19:39 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/02 16:54:42 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

static void			debug_put_fd_garbage(int key)
{
	char			*dummy;

	dummy = ft_itoa(key);
	ft_term_debug_putfd(dummy);
	ft_memdel((void**)&dummy);
}

static void			check_curs_lastco(t_line *line, t_term *term)
{
	int				cursor;

	cursor = line->cursor;
	if (cursor % term->con->co == 0
		&& line->current == line->last
		&& term->mode != 2
		&& cursor != 0)
	{
		ft_putchar(' ');
		ft_term_writetc(TC_LEFT);
	}
	else if (line->nbelem == cursor - term->prompt->promptlen
		&& (term->nbcharwrite + 3) % term->con->co == 0)
	{
		ft_putchar(' ');
		ft_term_writetc(TC_LEFT);
	}
}

int					ft_prompt_fnselector(t_prompt *prompt, t_term *term, \
											long key, t_control *controls)
{
	static char		tmp[2];
	int				ret;

	tmp[0] = key;
	if (key == 0)
		ft_prompt_handlefn(5, prompt, term, controls);
	else
	{
		if ((ret = ft_prompt_handlefn(key, prompt, term, controls)) == FAILURE)
		{
			if ((char)key > 0 && ft_isprint(key))
				ft_prompt_printable_key(prompt, term, key);
			else
				debug_put_fd_garbage(key);
		}
		check_curs_lastco(prompt->line, term);
	}
	return (SUCCESS);
}
