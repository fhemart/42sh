/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 05:50:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/04 00:48:08 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"
#include "ft_lstrprivate.h"

static t_lstr	*extend_str(t_lstr *str, const char *src)
{
	t_lstr		*tmp;
	size_t		slen;

	if (!str || !src)
		return (str);
	while (*src)
	{
		slen = ft_strlen((char*)src);
		if (!(tmp = ft_lstrnew_empty(str->totalsize)))
			return (str);
		tmp->type = T_NSTR;
		tmp->len = slen > (str->totalsize - 1) ? str->totalsize - 1 : slen;
		ft_memcpy(tmp->buffer, src, tmp->len);
		tmp->buffer[tmp->len] = '\0';
		ft_lstradd(&str, tmp);
		src += tmp->len;
	}
	return (str);
}

t_lstr			*ft_nstrcat(t_lstr **dst, const char *src)
{
	t_lstr		*tmp;
	size_t		slen;
	size_t		freespace;

	if (!src)
		return (*dst);
	tmp = *dst;
	slen = ft_strlen(src);
	if (slen > (freespace = ft_lstrfreespace(tmp)))
	{
		ft_memcpy(tmp->buffer + tmp->len, src, freespace);
		tmp->len += freespace;
		tmp->buffer[tmp->len] = '\0';
		*dst = extend_str(*dst, src + freespace);
		return (*dst);
	}
	ft_strcpy(tmp->buffer + tmp->len, src);
	tmp->len += slen;
	return (*dst);
}
