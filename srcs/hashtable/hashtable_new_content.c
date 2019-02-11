/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_new_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:20:01 by fhemart           #+#    #+#             */
/*   Updated: 2018/08/27 18:20:59 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

void		*hashtable_new_content(char *name, char *fullpath)
{
	t_hashcontent	*new_content;

	if (!name || !fullpath)
		return (NULL);
	if (!(new_content = malloc(sizeof(t_hashcontent))))
		return (NULL);
	ft_bzero(new_content, sizeof(t_hashcontent));
	new_content->len = ft_strlen(name);
	if (!(new_content->name = ft_strdup(name)) ||
		!(new_content->fullpath = ft_strdup(fullpath)))
	{
		ft_memdel((void**)&new_content);
		return (NULL);
	}
	return (new_content);
}
