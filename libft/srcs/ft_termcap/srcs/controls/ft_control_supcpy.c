/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_supcpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:55:42 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/22 18:58:33 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int				ft_control_supcpy(t_prompt *prompt, t_term *term)
{
	t_lstr		*freeme;

	if (!prompt->line->current)
		return (FALSE);
	freeme = NULL;
	ft_prompt_clean(term);
	if (term->lastkey == 12315 || !prompt->line->current->next)
		freeme = ft_control_cpyleft(prompt, term, &freeme);
	else
		freeme = ft_control_cpyright(prompt, term, &freeme);
	if (prompt->cpystr)
		ft_memdel((void**)&prompt->cpystr);
	prompt->cpystr = ft_lstr_tostring(freeme);
	ft_lstrdel(&freeme);
	ft_prompt_wrupdate(prompt, term);
	return (SUCCESS);
}
