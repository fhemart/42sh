/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdtoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:48:49 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 18:57:42 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hdtoi(int hexdec)
{
	const char	*hdstr;
	int			i;

	if (hexdec >= 'A' && hexdec <= 'F')
		hexdec -= 32;
	hdstr = LOWER_HEXDECSTR;
	i = 0;
	while (hdstr[i] != hexdec && hdstr[i])
		i++;
	return (i != 16 ? i : -1);
}

int	ft_strhextoi(char *str, int max_len, int *parsed_len)
{
	int		res;
	int		hex;
	int		plen;

	plen = 0;
	res = 0;
	while (plen < max_len && (hex = ft_hdtoi(str[plen])) != -1)
	{
		res = res * 16 + hex;
		plen++;
	}
	*parsed_len = plen;
	return (res);
}
