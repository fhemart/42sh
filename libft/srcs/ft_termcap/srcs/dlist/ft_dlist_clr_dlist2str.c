/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clr_dlist2str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 07:19:40 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 00:35:19 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

char			*ft_dlist_clr_dlist2str(t_line *root, t_term *term)
{
	char		*ret;
	t_cell		*curs;
	t_cell		*todel;
	int			len;
	int			i;

	len = root->nbelem;
	if (!(ret = malloc(len + 1)))
		return (NULL);
	ft_prompt_clean(term);
	curs = root->head;
	i = 0;
	while (curs)
	{
		if (curs->skip == FALSE)
			ret[i++] = curs->c;
		todel = curs;
		curs = curs->next;
		ft_dlist_rmonenode(term, todel, term->prompt->pool);
	}
	ret[i] = '\0';
	root->cursor = term->prompt->promptlen;
	return (ret);
}
