/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs_movli_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:47:04 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:39:00 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

int			ft_curs_movli_up(int origin, int newli, t_term *term)
{
	(void)term;
	while (origin != newli)
	{
		ft_term_writetc(TC_SCROLLUP);
		origin--;
	}
	return (TRUE);
}
