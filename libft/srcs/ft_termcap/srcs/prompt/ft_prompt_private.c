/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_private.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:15:50 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 00:41:49 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int				cpy_if_buff_full(int i, char *temp, t_prompt *prompt)
{
	(void)prompt;
	if (i == 255)
	{
		temp[i] = '\0';
		i = 0;
	}
	return (i);
}

int				tr_lastcol_nolastline(t_line *line, t_term *term)
{
	int			linepos;
	int			basepos;
	int			console_co;
	int			scrollcurs;

	basepos = line->cursor - term->prompt->promptlen;
	linepos = basepos - term->scrollcurs + SECU_OFFSET;
	console_co = term->con->co;
	scrollcurs = term->scrollcurs;
	if ((linepos % console_co == 0 && scrollcurs != 0) \
	|| (basepos == console_co - 1 && scrollcurs == 0)
	|| (basepos % console_co == console_co - 1 && scrollcurs == 0 \
	&& basepos > console_co))
		return (TRUE);
	return (FALSE);
}

char			*ft_dlist2str(t_line *root)
{
	char		*ret;
	t_cell		*curs;
	int			len;
	int			i;

	len = root->nbelem;
	if (!(ret = ft_memalloc(len + 1)))
		return (NULL);
	curs = root->head;
	i = 0;
	while (curs)
	{
		if (curs->skip == FALSE)
			ret[i++] = curs->c;
		curs = curs->next;
	}
	ret[i] = '\0';
	return (ret);
}
