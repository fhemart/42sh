/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstr_tostring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:42:10 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/13 16:55:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"

static void	ft_lstrcompile(char *ret, t_lstr *str, size_t len)
{
	while (str)
	{
		len -= str->len;
		ft_memcpy(ret + len, str->buffer, str->len);
		str = str->next;
	}
}

char		*ft_lstr_tostring(t_lstr *str)
{
	char	*ret;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_lstrlen(str);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	ret[len] = '\0';
	ft_lstrcompile(ret, str, len);
	return (ret);
}
