/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:09:49 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/19 11:28:41 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_atoull(const char *str)
{
	unsigned long long	result;
	int					sign;

	while (ft_isspace((int)*str))
		str++;
	sign = (*str == '+' || *str == '-') ? 44 - *str++ : 1;
	result = 0;
	while (ft_isdigit(*str))
		result = (result * 10) + ((*str++) - '0');
	return (result * sign);
}
