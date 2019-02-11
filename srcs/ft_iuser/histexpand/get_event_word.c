/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 17:06:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static char	*get_needle(char *word, t_chrmsk *wendmsk)
{
	size_t		len;
	char		*end;

	if ((end = chrmsk_getnext_match(word, wendmsk)))
		len = end - word;
	else if (word[(len = ft_strlen(word)) - 1] == '\n')
		len--;
	return (ft_strndup(word, len));
}

static void	update_data(char *needle, char *haystack, t_shdata *data)
{
	ft_strdel(&data->emark_laststr);
	data->emark_laststr = haystack;
	ft_strdel(&data->emark_lastneedle);
	data->emark_lastneedle = needle;
}

static int	get_event_strstr(t_histemark *hem, t_shdata *data, char *word)
{
	t_histentry	*entry;

	hem->strend++;
	if ((entry = hist_get_strstr(data->history->entries, word))
	&& (hem->eventsrc = ft_strdup(entry->string)))
	{
		update_data(word, hem->eventsrc, data);
		return (SUCCESS);
	}
	ft_strdel(&word);
	return (p_eeventnf(hem));
}

int			get_event_word(t_histemark *hem, t_shdata *data, t_chrmsk wendmsk)
{
	char		*word;
	t_histentry	*entry;

	if ((word = get_needle(hem->strend, &wendmsk)))
	{
		hem->strend += ft_strlen(word);
		if (hem->strbegin[1] == '?' && *hem->strend == '?')
			return (get_event_strstr(hem, data, word));
		if ((entry = hist_get_nmatch(data->history->entries, word))
		&& (hem->eventsrc = ft_strdup(entry->string)))
		{
			update_data(word, hem->eventsrc, data);
			return (SUCCESS);
		}
		ft_strdel(&word);
	}
	return (p_eeventnf(hem));
}
