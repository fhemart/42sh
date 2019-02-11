/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:30:24 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/17 18:01:29 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_strisdigit(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
