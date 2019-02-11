/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:18:26 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 03:33:38 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

int					ft_control_cpy(t_prompt *prompt, t_term *term)
{
	(void)term;
	if (!prompt->line->current)
		return (FALSE);
	if (prompt->cpystr)
		ft_memdel((void**)&prompt->cpystr);
	prompt->cpystr = ft_dlist2str(prompt->line);
	return (TRUE);
}
