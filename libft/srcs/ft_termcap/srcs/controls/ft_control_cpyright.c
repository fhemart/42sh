/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_cpyright.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:56:56 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 01:47:31 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

static void		cpy_and_clear(t_cell *curs, char *temp, t_term *term, \
									t_lstr **lstr)
{
	t_cell		*todell;
	int			i;
	t_prompt	*prompt;

	prompt = term->prompt;
	i = 0;
	todell = curs;
	temp[0] = '\0';
	while (curs)
	{
		if (cpy_if_buff_full(i, temp, prompt) == 0)
		{
			i = 0;
			*lstr = ft__strcat(lstr, temp);
		}
		if (curs->skip == FALSE)
			temp[i++] = curs->c;
		curs = curs->next;
		ft_dlist_rmonenode(term, todell, prompt->pool);
		todell = curs;
	}
	temp[i] = '\0';
}

t_lstr			*ft_control_cpyright(t_prompt *prompt, t_term *term, \
										t_lstr **lstr)
{
	char		temp[256];
	t_cell		*curs;

	if (*lstr)
		ft_lstrdel(lstr);
	if (prompt->line->current == prompt->line->head)
		curs = prompt->line->current;
	else
		curs = prompt->line->current->next;
	cpy_and_clear(curs, temp, term, lstr);
	*lstr = ft__strcat(lstr, temp);
	return (*lstr);
}
