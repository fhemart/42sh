/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_pasteleft.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 00:06:24 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 06:46:30 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int				ft_control_pasteleft(t_prompt *prompt)
{
	size_t		i;
	char		*cpystr;

	i = -1;
	cpystr = prompt->cpystr;
	while (cpystr[++i])
	{
		ft_dlist_addbeforenode(prompt->line->current, \
									cpystr[i], prompt->pool);
	}
	return (SUCCESS);
}
