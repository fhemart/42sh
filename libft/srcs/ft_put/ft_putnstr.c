/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:31:06 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 15:42:39 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putnstr(char *str, size_t n)
{
	size_t		len;

	if ((len = ft_strlen(str)) > n)
		len = n;
	if (write(1, str, len) == -1)
		return (FAILURE);
	return (SUCCESS);
}
