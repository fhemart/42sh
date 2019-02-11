/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordq_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:17:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static void	update_begend(int i, int wrange[2], char *begend[2], char *tstr)
{
	if (i < wrange[0])
		begend[0] = ft_strstr(begend[0], tstr) + ft_strlen(tstr);
	else if (i == wrange[0])
	{
		begend[0] = ft_strstr(begend[0], tstr);
		begend[1] = begend[0] + ft_strlen(tstr);
	}
	else if (i <= wrange[1])
		begend[1] = ft_strstr(begend[1], tstr) + ft_strlen(tstr);
}

static char	*word_star_except(t_tlexicon *tlex)
{
	t_token	*tok;

	tok = ft_queue_get(tlex->tokens);
	token_del(&tok);
	return (ft_memalloc(1));
}

char		*wordq_replace(int wrange[2], t_tlexicon *tlex, t_histemark *hem)
{
	char	*begend[2];
	char	*tokstr;
	t_token	*tok;
	int		i;
	int		qheight;

	i = -1;
	qheight = (int)ft_queue_get_height(tlex->tokens);
	begend[0] = hem->eventsrc;
	if (wrange[0] == EMARK_WRANGSTAR)
	{
		if (qheight == 1)
			return (word_star_except(tlex));
		wrange[0] = 1;
	}
	while (++i < qheight)
	{
		tok = ft_queue_get(tlex->tokens);
		if (!(tokstr = tok->content))
			tokstr = tkn_tostring(tlex->grammar, tok->type);
		update_begend(i, wrange, begend, tokstr);
		token_del(&tok);
	}
	return (ft_strndup(begend[0], begend[1] - begend[0]));
}
