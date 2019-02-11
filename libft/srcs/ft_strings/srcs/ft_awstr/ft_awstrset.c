/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_awstrset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 02:03:26 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 02:04:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_awstr.h"

int		ft_awstrset(t_awstr *dst, char c, size_t n)
{
	int		ret_value;

	ret_value = 0;
	if (!dst)
		return (-1);
	if (!n)
		return (0);
	if (dst->size + n >= STR_BUFFSIZE)
	{
		ret_value += ft_putawstr(dst);
		while (n >= STR_BUFFSIZE)
		{
			ft_memset(dst->buffer, c, STR_BUFFSIZE);
			write(1, dst->buffer, STR_BUFFSIZE);
			ret_value += STR_BUFFSIZE;
			n -= STR_BUFFSIZE;
		}
	}
	ft_memset(dst->buffer + dst->size, c, n);
	dst->size += n;
	return (ret_value);
}
