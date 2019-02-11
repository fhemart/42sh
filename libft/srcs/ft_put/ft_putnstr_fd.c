/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:31:57 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 15:33:56 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putnstr_fd(char *str, size_t n, int fd)
{
	size_t		len;

	if ((len = ft_strlen(str)) > n)
		len = n;
	if (write(fd, str, len) == -1)
		return (FAILURE);
	return (SUCCESS);
}
