/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:33:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/24 13:19:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_fd(char *str, int fd)
{
	if (ft_putstr_fd(str, fd) == FAILURE)
		return (FAILURE);
	return (ft_putchar_fd('\n', fd));
}
