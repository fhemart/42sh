/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 03:51:55 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 04:07:54 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

int				ft_control_exit(t_prompt *prompt, t_term *term)
{
	(void)term;
	if (prompt->inbsearch)
		ft_prompt_clr_exitbs_upd(prompt, term, FALSE);
	if (prompt->line->current)
		return (TRUE);
	prompt->exit = 0;
	prompt->done = 1;
	return (TRUE);
}
