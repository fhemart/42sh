/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_destroy_content.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:20:49 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/03 23:57:54 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

int					hashtable_destroy_content(void **content)
{
	t_hashcontent	*todel;

	if (!content || !*content)
		return (FAILURE);
	todel = (t_hashcontent*)*content;
	if (todel->name)
		ft_memdel((void**)&todel->name);
	if (todel->fullpath)
		ft_memdel((void**)&todel->fullpath);
	ft_memdel(content);
	return (SUCCESS);
}
