/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 22:59:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:04:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t flen;

	if (!*to_find)
		return ((char *)str);
	flen = ft_strlen(to_find);
	while (*str && flen-- >= n)
	{
		if (*str == *to_find
			&& ft_strnequ(str, to_find, n))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
