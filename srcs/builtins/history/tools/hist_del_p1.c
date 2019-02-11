/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_del_allentries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:05:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static void	hist_del_all_prev(t_histentry *from)
{
	if (!from)
		return ;
	hist_del_all_prev(from->prev);
	free(from->string);
	free(from);
}

static void	hist_del_all_next(t_histentry *from)
{
	if (!from)
		return ;
	hist_del_all_next(from->next);
	free(from->string);
	free(from);
}

void		hist_del_allentries(t_histentry **from)
{
	t_histentry		*dummy;

	if (!(dummy = *from))
		return ;
	hist_del_all_prev(dummy->prev);
	hist_del_all_next(dummy->next);
	ft_strdel(&dummy->string);
	ft_strdel(&dummy->modified);
	free(dummy);
	*from = NULL;
}

void		hist_del_entry(int *entry_count, t_histentry **entry)
{
	t_histentry		*dummy;

	if (!(dummy = *entry))
		return ;
	if (dummy->next)
	{
		dummy->next->prev = dummy->prev;
		*entry = dummy->next;
	}
	if (dummy->prev)
	{
		dummy->prev->next = dummy->next;
		*entry = dummy->prev;
	}
	ft_strdel(&dummy->string);
	free(dummy);
	if (entry_count)
		*entry_count -= 1;
}

int			hist_del_entryat(t_shhist *history, int at)
{
	int			reverse_count;
	t_histentry	*entry;

	if (at < 0 || at > history->entry_count)
		return (FAILURE);
	reverse_count = history->entry_count - at;
	if (!reverse_count)
		hist_del_entry(&history->entry_count, &history->entries);
	else
	{
		entry = history->entries;
		while (reverse_count--)
			entry = entry->prev;
		hist_del_entry(&history->entry_count, &entry);
	}
	return (SUCCESS);
}
