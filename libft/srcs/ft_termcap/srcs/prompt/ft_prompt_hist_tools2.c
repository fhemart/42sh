/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_hist_tools2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 07:25:35 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/04 16:34:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"
#include "ftsh.h"

int				hist_update_curr_histline(t_shhist *hist, char *line, \
										t_bool keep)
{
	t_histentry	*curr_entry;

	if (!(curr_entry = hist_get_current_histline(hist, TRUE)))
	{
		if (keep)
			ft_strdel(&line);
		return (SUCCESS);
	}
	hist_update_modified(curr_entry, line, keep);
	return (SUCCESS);
}

t_histentry		*hg_prev_chl(t_shhist *history)
{
	t_histentry	*entry;

	if ((entry = history->current_histline))
		return (entry->prev);
	return ((entry = history->entries));
}

t_histentry		*hg_next_chl(t_shhist *history)
{
	t_histentry	*entry;

	if ((entry = history->current_histline))
		return (entry->next);
	return (NULL);
}
