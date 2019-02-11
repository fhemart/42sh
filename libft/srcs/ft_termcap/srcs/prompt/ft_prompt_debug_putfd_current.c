/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_debug_putfd_current.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:35:01 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 01:20:59 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			ft_prompt_debug_putfd_current(t_cell *current)
{
	char		*dummy;
	char		dum[2];

	dum[1] = '\0';
	ft_term_debug_putfd("---- current ---------");
	dummy = ft_itoa(current->co);
	ft_term_debug_putfd("colone");
	ft_term_debug_putfd(dummy);
	ft_memdel((void**)&dummy);
	dummy = ft_itoa(current->li);
	ft_term_debug_putfd("ligne");
	ft_term_debug_putfd(dummy);
	ft_memdel((void**)&dummy);
	dum[0] = current->c;
	ft_term_debug_putfd("charactere");
	ft_term_debug_putfd(dum[0] == '\t' ? "\\t" : dum);
}
