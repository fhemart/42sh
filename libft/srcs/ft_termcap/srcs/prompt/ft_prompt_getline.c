/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_getline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:27:18 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:54:43 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

t_line				*ft_prompt_getline(t_prompt *prompt, t_term *term, \
										t_control *controls)
{
	long			key;

	while (prompt->done == 0)
	{
		ft_prompt_ifresise(term);
		ft_putstr("\x1B[0m");
		key = ft_term_readkey();
		ft_prompt_fnselector(prompt, term, key, controls);
		term->lastkey = key;
		ft_prompt_ifresise(term);
		if (PROMPT_DEBUG)
			ft_prompt_getline_debug(prompt->line, term);
	}
	term->mode = 1;
	return (prompt->line);
}
