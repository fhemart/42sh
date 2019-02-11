/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:31:06 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/14 16:06:00 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putstr(char *str)
{
	size_t		len;

	len = ft_strlen(str);
	if (write(1, str, len) == -1)
		return (FAILURE);
	return (SUCCESS);
}
