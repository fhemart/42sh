/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrnew_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 04:47:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/03 19:49:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"

t_lstr		*ft_lstrnew_empty(size_t size)
{
	t_lstr		*str;

	if (!size || !(str = (t_lstr*)malloc(sizeof(t_lstr) + size)))
		return (NULL);
	ft_bzero((void*)str, sizeof(t_lstr) + 1);
	str->totalsize = size;
	return (str);
}
