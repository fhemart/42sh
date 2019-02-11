/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:31:57 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/24 13:24:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putstr_fd(char *str, int fd)
{
	size_t		len;

	len = ft_strlen(str);
	if (write(fd, str, len) == -1)
		return (FAILURE);
	return (SUCCESS);
}
