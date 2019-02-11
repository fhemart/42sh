/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_hist_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:32:02 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 12:33:56 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void				recurs_suppress_modif(t_histentry *n, t_bool next)
{
	if (!n)
		return ;
	recurs_suppress_modif(next ? n->next : n->prev, next);
	ft_strdel(&n->modified);
	if (n->string)
		return ;
	if (n->prev)
	{
		if ((n->prev->next = n->next))
			n->next->prev = n->prev;
	}
	else
		n->next->prev = NULL;
	free(n);
}

void				suppress_ghost_entry(t_histentry **ghost)
{
	t_histentry		*entry;

	if ((entry = *ghost) && entry->modified && !entry->string)
	{
		if (entry->prev)
			entry->prev->next = entry->next;
		if (entry->next)
			entry->next->prev = entry->prev;
		free(entry->modified);
		free(entry);
		*ghost = NULL;
	}
}

void				hist_suppress_modified(t_shhist *hist)
{
	t_histentry	*entry;
	t_histentry	*dummy;

	if ((entry = hist->entries))
		suppress_ghost_entry(&entry->next);
	else
	{
		suppress_ghost_entry(&hist->current_histline);
		if (!(entry = hist->current_histline))
			return ;
	}
	while (entry->next)
		entry = entry->next;
	while (entry)
	{
		ft_strdel(&entry->modified);
		dummy = entry->prev;
		entry = dummy;
	}
}
