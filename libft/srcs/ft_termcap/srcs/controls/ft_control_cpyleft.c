/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_cpyleft.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:58:31 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 01:47:20 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

static t_lstr	*cpyleft_fillbuff(t_cell *curs, char *temp, \
									t_term *term, t_lstr *lstr)
{
	t_cell		*todell;
	t_prompt	*prompt;
	int			i;

	i = 0;
	todell = curs;
	prompt = term->prompt;
	while (curs && curs != prompt->line->current->next)
	{
		if (cpy_if_buff_full(i, temp, prompt) == 0)
		{
			i = 0;
			lstr = ft__strcat(&lstr, temp);
		}
		if (curs->skip == FALSE)
			temp[i++] = curs->c;
		curs = curs->next;
		ft_dlist_rmonenode(term, todell, prompt->pool);
		todell = curs;
	}
	temp[i] = '\0';
	return (lstr);
}

t_lstr			*ft_control_cpyleft(t_prompt *prompt, t_term *term, \
									t_lstr **lstr)
{
	char		temp[256];
	t_cell		*curs;

	temp[0] = '\0';
	if (*lstr)
		ft_lstrdel(lstr);
	curs = prompt->line->head;
	*lstr = cpyleft_fillbuff(curs, temp, term, *lstr);
	*lstr = ft__strcat(lstr, temp);
	prompt->line->cursor = prompt->promptlen;
	prompt->line->current = prompt->line->head;
	ft_prompt_ifresise(term);
	return (*lstr);
}
