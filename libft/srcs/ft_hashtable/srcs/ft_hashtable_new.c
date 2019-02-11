/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:33:52 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/03 23:45:08 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashtable.h"

int					ft_hashtable_new(t_hashtable **hashtable)
{
	if (!(*hashtable = malloc(sizeof(t_hashtable))))
	{
		*hashtable = NULL;
		return (FAILURE);
	}
	ft_bzero(*hashtable, sizeof(t_hashtable));
	return (SUCCESS);
}
