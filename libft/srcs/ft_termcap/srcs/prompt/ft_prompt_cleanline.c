/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_cleanline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:28:44 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/02 14:58:42 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int					ft_prompt_cleanline(void **content, t_pool *pool, \
										t_line *line)
{
	void			*tmp;
	void			*curs;
	int				count;

	count = 0;
	tmp = *content;
	curs = *content;
	while (curs)
	{
		if (curs == line->current)
			line->current = NULL;
		if (curs == line->last)
			line->last = NULL;
		ft_pool_giveback(pool, tmp);
		curs = ((t_list*)curs)->next;
		tmp = curs;
		count++;
	}
	*content = NULL;
	ft_pool_clear(pool);
	return (count);
}
