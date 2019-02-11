/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_ctrlc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:38:46 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/02 18:48:34 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ftsh.h"

int			ft_control_ctrlc(t_prompt *prompt, t_term *term)
{
	int		ret;

	if (prompt->inbsearch)
	{
		ft_prompt_clean(term);
		ft_prompt_exit_bsearch(term, TRUE);
	}
	go_to_endline(prompt, term, prompt->line);
	ret = ft_prompt_cleanline((void**)&term->prompt->line->head, prompt->pool,\
								prompt->line);
	prompt->line->nbelem -= ret;
	if (prompt->ps != 1)
		prompt->exit = -1;
	ft_control_enter(prompt, term);
	return (TRUE);
}
