/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:54:34 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int		get_wrange_min(int wrange[2], t_histemark *hem)
{
	if (ft_isdigit(*(++hem->strend)))
		wrange[0] = ft_atoi_movefw(&hem->strend);
	else if (*hem->strend++ == '^')
		wrange[0] = 1;
	else if (hem->strend[-1] == '$')
		wrange[0] = EMARK_WRANGLAST;
	else if (hem->strend[-1] == '*')
		wrange[0] = EMARK_WRANGSTAR;
	else if (hem->strend[-1] == '-')
	{
		wrange[0] = 0;
		hem->strend--;
	}
	else
	{
		if (hem->strend[-1] == '%')
			wrange[0] = EMARK_WRANGLASTSTR;
		else
		{
			wrange[0] = EMARK_WRANGALL;
			hem->strend -= 2;
		}
		return (ST_SUCCESS);
	}
	return (ST_CONTINUE);
}

static int		get_wrange_max(int wrange[2], t_histemark *hem)
{
	char		c;

	if (wrange[0] == EMARK_WRANGSTAR)
		return (SUCCESS);
	else if (ft_isdigit(*(++hem->strend)))
		wrange[1] = ft_atoi_movefw(&hem->strend);
	else if ((c = *hem->strend++) == '^')
		wrange[1] = 1;
	else
	{
		if (c != '$' && c != '*')
			hem->strend--;
		wrange[1] = EMARK_WRANGLAST;
	}
	return (SUCCESS);
}

static int		get_wrange(int wrange[2], t_histemark *hem, t_shdata *data)
{
	(void)data;
	if (*hem->strend != ':')
	{
		wrange[0] = EMARK_WRANGNO;
		return (SUCCESS);
	}
	if (get_wrange_min(wrange, hem) == ST_CONTINUE)
	{
		if (*hem->strend == '-')
			get_wrange_max(wrange, hem);
		else
			wrange[1] = EMARK_WRANGNO;
	}
	return (SUCCESS);
}

static int		get_word_not_laststr(t_histemark *hem)
{
	if (!(hem->replace = ft_memalloc(1)))
		return (FAILURE);
	return (SUCCESS);
}

int				get_words(t_histemark *hem, t_shdata *data)
{
	int			wrange[2];

	if (get_wrange(wrange, hem, data) == FAILURE)
		return (FAILURE);
	if (wrange[0] == EMARK_WRANGNO)
		return (SUCCESS);
	if (wrange[0] == EMARK_WRANGLASTSTR)
	{
		if (data->emark_laststr)
			return (get_word_laststr(hem, data));
		return (get_word_not_laststr(hem));
	}
	if (get_words_replace(wrange, hem) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
