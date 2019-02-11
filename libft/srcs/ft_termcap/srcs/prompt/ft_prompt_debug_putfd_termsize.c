/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_debug_putfd_termsize.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:36:17 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/07 11:13:52 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			ft_prompt_debug_putfd_termsize(t_con *con)
{
	char		*dummy;

	ft_term_debug_putfd("---- term size ------");
	dummy = ft_itoa(con->co);
	ft_term_debug_putfd(dummy);
	ft_memdel((void**)&dummy);
	dummy = ft_itoa(con->li);
	ft_term_debug_putfd(dummy);
	ft_memdel((void**)&dummy);
}
