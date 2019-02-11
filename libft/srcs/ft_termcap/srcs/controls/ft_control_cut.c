/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_cut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:12:21 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/22 18:58:15 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

static int		cut_fillbuff(t_cell *curs, char *temp, t_prompt *prompt, \
										t_lstr *lstr)
{
	int			i;

	i = 0;
	while (curs)
	{
		if (cpy_if_buff_full(i, temp, prompt) == 0)
		{
			i = 0;
			lstr = ft__strcat(&lstr, temp);
		}
		temp[i++] = curs->c;
		curs = curs->next;
		ft_dlist_rmnode(prompt->line, prompt->pool);
	}
	temp[i] = '\0';
	lstr = ft__strcat(&lstr, temp);
	return (SUCCESS);
}

int				ft_control_cut(t_prompt *prompt, t_term *term)
{
	static char	temp[256];
	t_cell		*curs;
	t_lstr		*freeme;

	freeme = NULL;
	curs = prompt->line->head;
	prompt->line->current = curs;
	if (freeme)
		ft_lstrclr(freeme);
	cut_fillbuff(curs, temp, prompt, freeme);
	if (prompt->cpystr)
		ft_memdel((void**)&prompt->cpystr);
	prompt->cpystr = ft_lstr_tostring(freeme);
	ft_lstrdel(&freeme);
	ft_prompt_clean(term);
	ft_putstr(prompt->prompt);
	prompt->line->cursor = prompt->promptlen;
	return (SUCCESS);
}
