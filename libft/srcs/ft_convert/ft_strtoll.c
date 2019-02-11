/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:09:49 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/19 17:05:09 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_strtoll(const char *str, int *errcode)
{
	t_ull	max_range;
	t_ull	result;
	int		sign;
	int		err_c;
	int		c;

	while (ft_isspace((c = *str)))
		str++;
	sign = (c == '+' || c == '-') ? 44 - *str++ : 1;
	max_range = sign == 1 ? LLONG_MAX : -(t_ull)LLONG_MIN;
	result = 0;
	err_c = 0;
	while (!err_c)
	{
		if (result > max_range)
			err_c = 3;
		else if (!ft_isdigit((c = (*str++))))
			err_c = c == 0 ? 1 : 2;
		else
			result = (result * 10) + (c - '0');
	}
	if (errcode)
		*errcode = err_c - 1;
	return (((long long)result) * sign);
}
