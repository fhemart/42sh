/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 02:32:16 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/05 14:35:20 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_byte(t_byte byte)
{
	t_byte bits;

	bits = 1 << 7;
	while (bits)
	{
		if (ft_putchar((byte & bits) ? '1' : '0') == FAILURE)
			return (FAILURE);
		bits >>= 1;
	}
	return (SUCCESS);
}
