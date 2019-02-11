/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:19:51 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 21:54:33 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strisspace(char *str)
{
	while (*str)
		if (!ft_isspace(*str++))
			return (FALSE);
	return (TRUE);
}
