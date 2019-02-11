/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 07:18:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/15 19:13:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_strcasecmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (ft_tolower(s1[i]) == ft_tolower(s2[i]) && s1[i])
		i++;
	return (ft_tolower((unsigned char)s1[i])
			- ft_tolower((unsigned char)s2[i]));
}
