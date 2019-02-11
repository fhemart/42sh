/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 03:43:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:42:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_astrlen(char **astr, size_t alen)
{
	size_t		ret;

	ret = 0;
	while (alen--)
		ret += ft_strlen(astr[alen]);
	return (ret);
}
