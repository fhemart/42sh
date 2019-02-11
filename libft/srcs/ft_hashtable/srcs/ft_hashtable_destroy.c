/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:37:51 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 03:26:52 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

static int			hashtable_destroy_indexes(void **content, int (*del)())
{
	void			**todel;

	todel = content;
	if (!content || !*content)
		return (FAILURE);
	if (((t_list*)*content)->next)
		hashtable_destroy_indexes((void**)&((t_list*)*content)->next, del);
	del(content);
	return (SUCCESS);
}

int					ft_hashtable_destroy(t_hashtable **hashtable, int (*del)())
{
	int				i;

	if (!hashtable || !*hashtable)
		return (SUCCESS);
	i = 0;
	while (i < HASHTABLE_SIZE)
	{
		if ((*hashtable)->indexes[i])
			hashtable_destroy_indexes((void **)&(*hashtable)->indexes[i], del);
		i++;
	}
	ft_memdel((void **)hashtable);
	return (SUCCESS);
}
