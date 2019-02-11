/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_ctrlg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:47:36 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 03:53:16 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

int			ft_control_ctrlg(t_prompt *prompt, t_term *term)
{
	if (!prompt->inbsearch)
		return (TRUE);
	ft_prompt_clr_exitbs_upd(prompt, term, TRUE);
	return (TRUE);
}
