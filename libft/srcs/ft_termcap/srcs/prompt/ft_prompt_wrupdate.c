/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_wrupdate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:58:32 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 09:21:19 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

int			wrupdate_in_tr(t_term *term, t_prompt *prompt)
{
	int		wrat;

	if (PROMPT_DEBUG)
		ft_term_debug_putfd("TR MODE");
	wrat = (prompt->line->cursor - prompt->promptlen) - term->con->co;
	wrat = wrat < prompt->promptlen ? 0 : wrat;
	term->mode = MODE_TRUNC;
	ft_term_writetc(TC_INTI);
	if (prompt->line->current != prompt->line->last)
		prompt->hasinsert = 1;
	term->nbcharwrite = ft_prompt_wrat2(term, wrat);
	prompt->hasinsert = 0;
	term->scrollcurs = wrat;
	return (SUCCESS);
}

int			wrupdate_in_nm(t_term *term, t_prompt *prompt)
{
	t_cell	*curs;
	int		nop;

	if (PROMPT_DEBUG)
		ft_term_debug_putfd("NM MODE");
	if (term->mode == MODE_TRUNC)
	{
		if (PROMPT_DEBUG)
			ft_term_debug_putfd("OUT TR MODE");
		term->mode = MODE_NORMAL;
		ft_term_writetc(TC_INTE);
	}
	ft_putstr(prompt->prompt);
	curs = term->prompt->line->head;
	nop = 1;
	if (!curs)
		nop = 0;
	while (curs)
	{
		ft_prompt_writechar(curs, term, term->prompt);
		curs = curs->next;
	}
	if (nop)
		ft_prompt_returnafterwr(term);
	return (SUCCESS);
}

int			ft_prompt_wrupdate(t_prompt *prompt, t_term *term)
{
	if (PROMPT_DEBUG)
		ft_term_debug_putfd("WRLINE");
	if (if_wrupdate_in_nm(term, prompt))
		return (wrupdate_in_nm(term, prompt));
	if (if_wrupdate_in_tr(term, prompt))
		return (wrupdate_in_tr(term, prompt));
	return (wrupdate_in_nm(term, prompt));
}
