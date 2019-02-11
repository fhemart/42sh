/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:07:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static char		*hist_dup_true_nentry(t_shdata *data, int n)
{
	t_prompt	*prompt;
	int			sline_iter;
	int			lstheight;
	t_list		*lst;
	char		*ret;

	prompt = data->term->prompt;
	lstheight = ft_lstheight(prompt->str_line->next);
	sline_iter = prompt->sline_iter;
	if (n < 0 && (lst = prompt->str_line->next) && -(++n) <= lstheight)
	{
		while (++n - 1)
			lst = lst->next;
		if (((char*)lst->content)[lst->content_size - 2] == '\n')
			return (ft_strndup(lst->content, lst->content_size - 2));
		return (ft_strdup(lst->content));
	}
	if ((ret = hist_get_nentry(data->history, n < 0 ? n - lstheight : n)))
		return (ft_strdup(ret));
	return (NULL);
}

static int		get_event_nline(t_histemark *hem, t_shdata *data, int nline)
{
	if (!nline || !(hem->eventsrc = hist_dup_true_nentry(data, nline)))
		return (p_eeventnf(hem));
	return (SUCCESS);
}

static int		get_event_hline(t_histemark *hem, t_shdata *data)
{
	int		nline;

	nline = ft_atoi_movefw(&hem->strend);
	return (get_event_nline(hem, data, nline));
}

static int		get_event_typedlsofar(t_histemark *hem)
{
	size_t		len;
	char		*eventsrc;

	len = hem->strbegin - *hem->line;
	if (!(eventsrc = ft_strnew(len)))
		return (FAILURE);
	ft_memcpy(eventsrc, *hem->line, len);
	eventsrc[len] = '\0';
	hem->eventsrc = eventsrc;
	hem->strend++;
	return (SUCCESS);
}

int				get_event(t_histemark *hem, char *emarkstr, t_shdata *data)
{
	char		c;

	if (char_match_pattern((c = *emarkstr), &hem->endmsk))
		return (FAILURE);
	if (ft_isdigit(c) || (c == '-' && ft_isdigit(emarkstr[1])))
		return (get_event_hline(hem, data));
	if (c == '!')
	{
		hem->strend++;
		return (get_event_nline(hem, data, -1));
	}
	if (c == '#')
		return (get_event_typedlsofar(hem));
	if (c == '?')
	{
		hem->strend++;
		return (get_event_word(hem, data, new_chrmsk(HISTEMARK_QWEND_MSK)));
	}
	return (get_event_word(hem, data, new_chrmsk(HISTEMARK_WEND_MSK)));
}
