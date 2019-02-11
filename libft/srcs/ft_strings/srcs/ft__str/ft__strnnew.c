/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__strnnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 04:47:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/06/08 19:25:50 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"
#include "ft_lstrprivate.h"

t_lstr		*ft__strnnew(const char *src, size_t n)
{
	t_lstr		*str;
	size_t		size;

	if (!n)
		return (NULL);
	if ((size = ft_strlen(src)) > n)
		size = n;
	if (!src || !(str = ft_lstrnew_empty(size + 1)))
		return (NULL);
	str->type = T__STR;
	str->len = size;
	ft_strncpy(str->buffer, src, size);
	return (str);
}
