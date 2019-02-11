/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_debug_putfd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:50:02 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 10:05:10 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

void							ft_term_debug_putfd(char *str)
{
	int					debug_fd;

	if (TC_DEBUG == 0)
		return ;
	debug_fd = open("debug.log", O_APPEND | O_CREAT | O_WRONLY, 0644);
	if (debug_fd == -1)
		return ;
	ft_putendl_fd(str, debug_fd);
	close(debug_fd);
}
