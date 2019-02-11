/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 17:02:11 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_histentry	*hist_get_nmatch(t_histentry *from, char *nmatch)
{
	size_t	nmlen;

	nmlen = ft_strlen(nmatch);
	while (from)
	{
		if (ft_strnequ(from->string, nmatch, nmlen))
			break ;
		from = from->prev;
	}
	return (from);
}

t_histentry	*hist_get_strstr(t_histentry *from, char *nmatch)
{
	char	*cmp;

	while (from)
	{
		cmp = hist_get_modified(from);
		if (ft_strstr(cmp, nmatch))
			break ;
		from = from->prev;
	}
	return (from);
}
