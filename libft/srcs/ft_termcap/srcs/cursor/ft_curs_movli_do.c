/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs_movli_do.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:48:21 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:37:10 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

int			ft_curs_movli_do(int origin, int newli, t_term *term)
{
	(void)term;
	while (origin != newli)
	{
		ft_term_writetc(TC_SCROLLDO);
		origin++;
	}
	return (TRUE);
}
