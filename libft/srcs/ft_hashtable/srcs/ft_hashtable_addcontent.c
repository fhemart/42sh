/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_addcontent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:31:27 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 03:25:53 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

static void			*hashtable_get_lastcontent(void *content)
{
	t_list			*lastcontent;
	t_list			*nextcontent;

	lastcontent = content;
	nextcontent = content;
	while (nextcontent)
	{
		lastcontent = nextcontent;
		nextcontent = nextcontent->next;
	}
	return ((void*)lastcontent);
}

int					ft_hashtable_addcontent(char *fullpath, \
					char *name, t_hashtable *hashtable, void *(*new_content)())
{
	int				index;
	void			*newpos;

	if (!hashtable)
		return (FAILURE);
	index = (ft_hash_joaat(name, ft_strlen(name)) % HASHTABLE_SIZE);
	if (hashtable->indexes[index])
	{
		newpos = hashtable_get_lastcontent(hashtable->indexes[index]);
		if (!(((t_list*)newpos)->next = new_content(name, fullpath)))
			return (-2);
		return (TRUE);
	}
	else
	{
		if (!(hashtable->indexes[index] = new_content(name, fullpath)))
			return (-3);
		return (2);
	}
	return (FALSE);
}
