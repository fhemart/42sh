/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msk_new_chrmsk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:29:02 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/03 19:42:30 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chrmsk	ft_msk_new_chrmsk(char *str)
{
	t_chrmsk	ret;
	int			i;
	int			j;

	ft_bzero(&ret, sizeof(ret));
	while (*str)
	{
		i = *str / 32;
		j = *str % 32;
		ret.pattern[i] |= 1 << j;
		str++;
	}
	return (ret);
}
