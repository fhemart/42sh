/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:47:39 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 22:55:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dlen;
	size_t slen;

	slen = ft_strlen(src);
	if (size < (dlen = ft_strlen(dst)))
		return (slen + size);
	size -= dlen;
	while (*src && size > 1)
	{
		*(dst++ + dlen) = *src++;
		size--;
	}
	*(dst + dlen) = '\0';
	return (dlen + slen);
}
