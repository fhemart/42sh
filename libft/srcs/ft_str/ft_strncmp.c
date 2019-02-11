/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:04:57 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/15 19:15:08 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	if (!n)
		return (0);
	i = 0;
	while (ft_tolower(s1[i]) == ft_tolower(s2[i]) && s1[i] && i < n - 1)
		i++;
	return (ft_tolower((unsigned char)s1[i])
			- ft_tolower((unsigned char)s2[i]));
}
