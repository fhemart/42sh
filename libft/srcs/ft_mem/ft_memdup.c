/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:41:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 13:02:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(const void *src, size_t size)
{
	void	*dup;

	if (!(dup = ft_memalloc(size)))
		return (NULL);
	return (ft_memcpy(dup, src, size));
}
