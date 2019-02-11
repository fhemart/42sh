/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_movewordfw.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 03:55:40 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 06:46:11 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int					ft_control_movewordfw(t_prompt *prompt, t_term *term)
{
	int				spacebetween;

	spacebetween = ft_dlist_haswordfw(term);
	while (spacebetween)
	{
		ft_control_right(prompt, term);
		spacebetween--;
	}
	return (TRUE);
}
