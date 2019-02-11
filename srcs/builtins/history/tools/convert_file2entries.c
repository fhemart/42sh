/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file2entries.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:00:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static char		*cf2e_skip_endl(char *start)
{
	char	*ret;

	if ((ret = ft_strchr(start, '\n')))
		while (*ret == '\n')
			*ret++ = '\0';
	return (ret);
}

static void		cf2e_update_entry(t_histentry *new_entry, t_histentry **head, \
							int *tstamp, int *entry_count)
{
	int		ts;

	*entry_count += 1;
	hist_ins_entry(head, new_entry);
	new_entry->saved = TRUE;
	if ((ts = *tstamp) == -1)
		return ;
	new_entry->timestamp = ts;
	*tstamp = -1;
}

t_histentry		*convert_file2entries(t_histentry *head, char *file, \
									int *entry_count)
{
	t_histentry	*new_entry;
	char		*endl;
	int			tstamp;

	tstamp = -1;
	while (file && *file)
	{
		endl = cf2e_skip_endl(file);
		if (*file == '#')
			tstamp = ft_strisdigit(file + 1) ? ft_atoi(file + 1) : -1;
		else if ((new_entry = hist_new_entry(file)))
			cf2e_update_entry(new_entry, &head, &tstamp, entry_count);
		file = endl;
	}
	return (head);
}

t_histentry		*convert_file2entries_nd(t_histentry *head, char *file, \
										int *entry_count, t_histbook *from)
{
	t_histentry	*new_entry;
	char		*endl;
	int			skip;
	int			tstamp;

	skip = from->line_read;
	while (file && *file)
	{
		endl = cf2e_skip_endl(file);
		if (*file == '#')
			tstamp = !skip && ft_strisdigit(file + 1) ? ft_atoi(file + 1) : -1;
		if (skip)
			skip--;
		else if ((new_entry = hist_new_entry(file)))
			cf2e_update_entry(new_entry, &head, &tstamp, entry_count);
		file = endl;
	}
	return (head);
}
