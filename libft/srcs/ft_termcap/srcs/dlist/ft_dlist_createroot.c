/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_createroot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:04:52 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/03 15:59:09 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_line			*ft_dlist_createroot(void)
{
	t_line		*new_line;

	if (!(new_line = malloc(sizeof(t_line))))
		return (NULL);
	ft_bzero(new_line, sizeof(t_line));
	return (new_line);
}
