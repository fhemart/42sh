/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_hystoryup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:30:30 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/04 16:33:25 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"
#include "ftsh.h"

int				history_move(t_prompt *prompt, t_term *term, t_bool up)
{
	t_histentry	*curr_entry;
	t_shhist	*history;
	char		*line;
	int			inbs;

	if ((inbs = prompt->inbsearch))
		ft_prompt_exit_bsearch(term, FALSE);
	history = ((t_iuser*)prompt->cparam)->shdata->history;
	hist_get_current_histline(history, TRUE);
	if ((curr_entry = up == TRUE ? hg_prev_chl(history) : hg_next_chl(history)))
	{
		if (!(line = ft_dlist_clr_dlist2str(prompt->line, term)))
			return (FAILURE);
		hist_update_curr_histline(history, line, TRUE);
		history->current_histline = curr_entry;
		line = hist_get_modified(history->current_histline);
		ft_dlist_str2dlist(line, term);
		ft_prompt_wrupdate(prompt, term);
	}
	if (inbs)
	{
		ft_prompt_clean(term);
		ft_prompt_wrupdate(prompt, term);
	}
	return (SUCCESS);
}

int				ft_control_hystoryup(t_prompt *prompt, t_term *term)
{
	if (!((t_iuser*)prompt->cparam)->shdata->history->entries)
		return (SUCCESS);
	return (history_move(prompt, term, TRUE));
}

int				ft_control_hystorydo(t_prompt *prompt, t_term *term)
{
	if (!((t_iuser*)prompt->cparam)->shdata->history->entries)
		return (SUCCESS);
	return (history_move(prompt, term, FALSE));
}
