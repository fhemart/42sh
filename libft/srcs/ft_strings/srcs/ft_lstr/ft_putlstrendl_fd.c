/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstrendl_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:26:46 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/03 19:49:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"

int		ft_putlstrendl_fd(t_lstr *str, int fd)
{
	if (ft_putlstr_fd(str, fd) == -1)
		return (-1);
	return (ft_putchar_fd('\n', fd));
}
