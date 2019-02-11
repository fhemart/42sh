/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_awstrncat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 02:03:26 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 02:04:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_awstr.h"

int		ft_awstrncat(t_awstr *dst, const char *src, size_t n)
{
	int		ret_value;

	ret_value = 0;
	if (!dst || !src)
		return (-1);
	if (!n)
		return (0);
	if (dst->size + n >= STR_BUFFSIZE)
	{
		ret_value += ft_putawstr(dst);
		while (n >= STR_BUFFSIZE)
		{
			write(1, src, STR_BUFFSIZE);
			src += STR_BUFFSIZE;
			n -= STR_BUFFSIZE;
			ret_value += STR_BUFFSIZE;
		}
	}
	ft_memcpy(dst->buffer + dst->size, src, n);
	dst->size += n;
	return (ret_value);
}
