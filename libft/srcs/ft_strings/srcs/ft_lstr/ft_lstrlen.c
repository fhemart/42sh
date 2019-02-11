/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:24:00 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/13 11:38:48 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"

size_t	ft_lstrlen(t_lstr *str)
{
	size_t	len;

	len = 0;
	while (str)
	{
		len += str->len;
		str = str->next;
	}
	return (len);
}
