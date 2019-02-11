/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 06:29:59 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 00:45:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_byte			*d;
	const t_byte	*s;

	d = (t_byte *)dest;
	s = (const t_byte *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
