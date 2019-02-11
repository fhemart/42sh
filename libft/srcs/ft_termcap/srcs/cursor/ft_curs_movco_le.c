/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs_movco_le.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:49:35 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:36:59 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

int			ft_curs_movco_le(int origin, int newco, t_term *term)
{
	(void)term;
	while (origin != newco)
	{
		ft_term_writetc(TC_LEFT);
		origin--;
	}
	return (TRUE);
}
