/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_str2dlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 06:48:14 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 18:46:39 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

static void		tab_case(t_prompt *prompt, t_term *term)
{
	int			i;

	i = -1;
	while (++i < 3)
	{
		ft_dlist_addnode(prompt->line, ' ', prompt->pool);
		prompt->line->current->skip = TRUE;
		prompt->line->cursor += 1;
		if (term->mode == MODE_TRUNC)
			term->nbcharwrite += 1;
	}
}

void			ft_dlist_str2dlist(char *src, t_term *term)
{
	t_prompt	*prompt;
	int			i;

	prompt = term->prompt;
	i = -1;
	while (src[++i])
	{
		if (ft_dlist_addnode(prompt->line, src[i], prompt->pool) == FAILURE)
			continue ;
		prompt->line->cursor += 1;
		if (term->mode == MODE_TRUNC)
			term->nbcharwrite += 1;
		if (src[i] == '\t')
			tab_case(prompt, term);
	}
}
