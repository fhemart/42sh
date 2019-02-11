/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__strncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 05:50:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/20 12:34:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"
#include "ft_lstrprivate.h"

t_lstr			*ft__strncat(t_lstr **dst, const char *src, size_t n)
{
	t_lstr		*tmp;
	size_t		slen;
	size_t		freespace;

	if (!n)
		return (*dst);
	if (!*dst)
		return (ft__strnnew(src, n));
	tmp = *dst;
	if ((slen = ft_strlen(src)) > n)
		slen = n;
	if (slen > (freespace = ft_lstrfreespace(tmp)))
	{
		ft_strncpy(tmp->buffer + tmp->len, src, freespace);
		tmp->len += freespace;
		ft_lstradd(&tmp, ft__strnnew(src + freespace, slen - freespace));
		*dst = tmp;
		return (*dst);
	}
	ft_strncpy(tmp->buffer, src, slen);
	tmp->len += slen;
	return (*dst);
}
