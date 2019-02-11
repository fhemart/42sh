/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 07:50:42 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 18:21:42 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t slen;

	slen = ft_strlen(s) + 1;
	while (slen)
	{
		if (s[--slen] == (char)c)
			return ((char*)(s + slen));
	}
	return (NULL);
}
