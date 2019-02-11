/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_movewordba.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 03:57:20 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 06:45:47 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int					ft_control_movewordba(t_prompt *prompt, t_term *term)
{
	int				spacebetween;

	spacebetween = ft_dlist_haswordba(term);
	while (spacebetween)
	{
		ft_control_left(prompt, term);
		spacebetween--;
	}
	return (TRUE);
}
