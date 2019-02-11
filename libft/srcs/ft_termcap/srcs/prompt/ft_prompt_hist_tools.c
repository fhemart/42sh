/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_hist_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 07:22:00 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/04 16:29:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"
#include "ftsh.h"

int				hist_update_modified(t_histentry *entry, char *mod, t_bool keep)
{
	if (!entry)
		return (FAILURE);
	ft_strdel(&entry->modified);
	if (!keep)
	{
		if (!(entry->modified = ft_strdup(mod)))
			return (FAILURE);
	}
	else
		entry->modified = mod;
	return (SUCCESS);
}

t_histentry		*hist_new_empty_entry(t_histentry *prev)
{
	t_histentry	*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		return (NULL);
	if ((new->prev = prev))
		prev->next = new;
	return (new);
}

char			*hist_get_modified(t_histentry *entry)
{
	if (!entry)
		return (NULL);
	return (entry->modified ? entry->modified : entry->string);
}

t_histentry		*create_current_histline(t_shhist *hist)
{
	t_histentry	*entry;

	if (!(entry = hist_new_empty_entry(hist->entries)))
		return (NULL);
	hist->current_histline = entry;
	return (entry);
}

t_histentry		*hist_get_current_histline(t_shhist *hist, t_bool create)
{
	t_histentry	*curr_entry;

	if (!(curr_entry = hist->current_histline) && create)
		return (create_current_histline(hist));
	return (curr_entry);
}
