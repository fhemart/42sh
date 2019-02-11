/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_awstrrpad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 02:03:26 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 02:07:27 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_awstr.h"

int		ft_awstrrpad(t_awstr *dst, const char *src, size_t n, t_awpad pad)
{
	int		ret_value1;
	int		ret_value2;

	ret_value1 = ft_awstrncat(dst, src, n);
	if (ret_value1 != -1)
	{
		if (pad.height > n)
			ret_value2 = ft_awstrset(dst, pad.c, pad.height - n);
		else
			ret_value2 = 0;
	}
	if (ret_value1 != -1 && ret_value2 != -1)
		return (ret_value1 + ret_value2);
	return (-1);
}
