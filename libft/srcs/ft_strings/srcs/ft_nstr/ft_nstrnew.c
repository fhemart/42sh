/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 04:47:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/03 22:12:43 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"
#include "ft_lstrprivate.h"

t_lstr		*ft_nstrnew(const char *src, size_t n)
{
	t_lstr		*str;

	if (!(str = ft_lstrnew_empty(n + 1)))
		return (NULL);
	str->type = T_NSTR;
	str->len = 0;
	return (ft_nstrcat(&str, src));
}
