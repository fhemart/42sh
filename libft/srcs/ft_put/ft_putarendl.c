/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarendl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:31:06 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/24 13:23:52 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putarendl(char **arstr)
{
	if (!arstr)
		return (SUCCESS);
	while (*arstr)
	{
		if (ft_putendl(*arstr) == FAILURE)
			return (FAILURE);
		arstr++;
	}
	return (SUCCESS);
}
