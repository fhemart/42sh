/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg_hash_joaat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:40:26 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 02:36:52 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long		ft_hash_joaat(char *key, size_t len)
{
	unsigned long	hash;
	size_t			i;

	i = 0;
	hash = 0;
	while (i < len)
	{
		hash += key[i++];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}
