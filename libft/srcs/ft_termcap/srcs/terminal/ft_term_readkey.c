/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_readkey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:51:20 by fhemart           #+#    #+#             */
/*   Updated: 2018/07/07 00:36:37 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

long							ft_term_readkey(void)
{
	static long					key;
	int							nbread;

	nbread = 0;
	key = 0;
	nbread = read(0, &key, sizeof(key));
	if (nbread == 0)
		key = 0;
	return (key);
}
