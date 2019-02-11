/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_ltoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 02:57:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/19 12:03:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nblen(unsigned int n)
{
	size_t len;

	len = 0;
	while ((n /= 10) > 0)
		len++;
	return (len);
}

char			*ft_static_ltoa(int n)
{
	static char		str[21];
	unsigned long	nb;
	size_t			len;

	nb = n < 0 ? (unsigned long)-n : (unsigned long)n;
	len = nblen(nb) + ((n >= 0) ? 1 : 2);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	str[--len] = (nb % 10) + '0';
	while ((nb /= 10))
		str[--len] = (nb % 10) + '0';
	return (str);
}
