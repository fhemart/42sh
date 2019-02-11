/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 05:50:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/06/08 19:10:20 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"
#include "ft_lstrprivate.h"

static t_lstr	*extend_str(t_lstr *str, const char *src, size_t n)
{
	t_lstr		*tmp;
	size_t		slen;

	if (!str || !src)
		return (str);
	while (*src && n)
	{
		if ((slen = ft_strlen(src)) > n)
			slen = n;
		if (!(tmp = ft_lstrnew_empty(str->totalsize)))
			return (str);
		tmp->type = T_NSTR;
		tmp->len = slen > (str->totalsize - 1) ? str->totalsize - 1 : slen;
		ft_memcpy(tmp->buffer, src, tmp->len);
		tmp->buffer[tmp->len] = '\0';
		ft_lstradd(&str, tmp);
		src += tmp->len;
		n -= tmp->len;
	}
	return (str);
}

t_lstr			*ft_nstrncat(t_lstr **dst, const char *src, size_t n)
{
	t_lstr		*tmp;
	size_t		slen;
	size_t		freespace;

	if (!src || !n)
		return (*dst);
	tmp = *dst;
	if ((slen = ft_strlen(src)) > n)
		slen = n;
	if (slen > (freespace = ft_lstrfreespace(tmp)))
	{
		ft_memcpy(tmp->buffer + tmp->len, src, freespace);
		tmp->len += freespace;
		tmp->buffer[tmp->len] = '\0';
		*dst = extend_str(*dst, src + freespace, slen - freespace);
		return (*dst);
	}
	ft_strncpy(tmp->buffer + tmp->len, src, slen);
	tmp->len += slen;
	return (*dst);
}
