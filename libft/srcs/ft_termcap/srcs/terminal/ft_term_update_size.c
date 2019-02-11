/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_update_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 06:24:39 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/03 17:04:05 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			ft_term_update_size(t_con *con, struct winsize *ws)
{
	con->co = ws->ws_col;
	con->li = ws->ws_row;
	con->size = con->co * con->li;
}
