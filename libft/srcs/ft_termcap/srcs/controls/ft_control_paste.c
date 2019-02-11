/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_paste.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:25:16 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/10 20:12:37 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int				ft_control_paste(t_prompt *prompt, t_term *term)
{
	if (!prompt->cpystr)
		return (FALSE);
	ft_control_pasteright(prompt, term);
	if (PROMPT_DEBUG)
		ft_dlist_debug_print(prompt->line);
	ft_prompt_ifresise(term);
	ft_prompt_wrupdate(prompt, term);
	return (SUCCESS);
}
