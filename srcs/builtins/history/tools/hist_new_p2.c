/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_new_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:13:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_histentry	*hist_new_entry(char *str)
{
	t_histentry		*ret;

	if (!(ret = (t_histentry*)ft_memalloc(sizeof(*ret)))
	|| !(ret->string = ft_strdup(str)))
	{
		ft_memdel((void**)&ret);
		return (NULL);
	}
	time(&ret->timestamp);
	return (ret);
}

t_histbook	*hist_new_book(char *histfile, int line_read)
{
	t_histbook	*ret;

	if (!(ret = (t_histbook*)ft_memalloc(sizeof(*ret))))
		return (NULL);
	ret->filename = ft_strdup(histfile);
	ret->line_read = line_read;
	return (ret);
}
