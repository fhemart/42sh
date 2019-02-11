/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:30:24 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/19 11:04:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_strisnumeric(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	return (ft_strisdigit(str));
}
