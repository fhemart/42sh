/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:11:50 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/02 13:06:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;

	if (!s1)
	{
		if (s2)
			return (ft_strdup(s2));
		else
			return (NULL);
	}
	else if (!s2)
		return (ft_strdup(s1));
	else if (!(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}
