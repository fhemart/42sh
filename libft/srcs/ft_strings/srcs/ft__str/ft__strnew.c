/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__strnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 04:47:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/13 11:34:51 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"
#include "ft_lstrprivate.h"

t_lstr		*ft__strnew(const char *src)
{
	t_lstr		*str;
	size_t		size;

	size = ft_strlen(src) + 1;
	if (!src || !(str = ft_lstrnew_empty(size)))
		return (NULL);
	str->type = T__STR;
	str->len = size - 1;
	ft_strcpy(str->buffer, src);
	return (str);
}
