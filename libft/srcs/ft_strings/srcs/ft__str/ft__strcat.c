/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__strcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 05:50:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/09 14:35:29 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"
#include "ft_lstrprivate.h"

t_lstr			*ft__strcat(t_lstr **dst, const char *src)
{
	t_lstr		*tmp;
	size_t		slen;
	size_t		freespace;

	if (!dst || !*dst)
		return ((*dst = ft__strnew(src)));
	tmp = *dst;
	if ((slen = ft_strlen(src)) == 0)
		return (tmp);
	if (slen > (freespace = ft_lstrfreespace(tmp)))
	{
		ft_strncpy(tmp->buffer + tmp->len, src, freespace);
		tmp->len += freespace;
		ft_lstradd(&tmp, ft__strnew(src + freespace));
		*dst = tmp;
		return (*dst);
	}
	ft_strcpy(tmp->buffer, src);
	tmp->len += slen;
	return (*dst);
}
