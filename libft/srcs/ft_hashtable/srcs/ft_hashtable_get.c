/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:28:44 by fhemart           #+#    #+#             */
/*   Updated: 2018/08/27 18:29:03 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

void				*ft_hashtable_get(t_hashtable *hashtable, \
						char *tosearch)
{
	int				index;
	t_list			*curs;

	curs = NULL;
	if (!hashtable || !*tosearch)
		return (NULL);
	index = (ft_hash_joaat(tosearch, ft_strlen(tosearch)) % HASHTABLE_SIZE);
	if (!hashtable->indexes[index])
		return (NULL);
	curs = hashtable->indexes[index];
	while (curs)
	{
		if (ft_strcmp(tosearch, ((t_hashcontent*)curs)->name) == 0)
			return (curs);
		curs = curs->next;
	}
	return (NULL);
}
