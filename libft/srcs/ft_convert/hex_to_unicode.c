/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:17:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/07 13:17:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_unicode	hex_to_unicode(char *hptr, char **endptr, int size)
{
	int		ucode;
	int		c;

	ucode = 0;
	while (size-- && (c = ft_hdtoi(*hptr)) != -1)
	{
		ucode = ucode * 16 + c;
		hptr++;
	}
	*endptr = hptr;
	return (convert_unicode(ucode));
}
