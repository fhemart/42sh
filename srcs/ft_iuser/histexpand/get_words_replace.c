/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_words_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:19:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static void	remove_nltok(t_queue *tokens)
{
	t_token *tok;

	if ((tok = ft_queue_lookback(tokens))
	&& tok->type == TNEWLINE)
	{
		ft_queue_getback(tokens);
		token_del(&tok);
	}
}

static int	set_wrangeall(int wrange[2], int qheight)
{
	wrange[0] = 0;
	wrange[1] = qheight;
	return (SUCCESS);
}

static int	is_valid_wrange(int wrange[2], t_queue *tokq, t_histemark *hem)
{
	int		qheight;
	t_token	*tok;

	remove_nltok(tokq);
	qheight = (int)ft_queue_get_height(tokq);
	if (wrange[0] == EMARK_WRANGALL)
		return (set_wrangeall(wrange, qheight));
	else if (wrange[0] == EMARK_WRANGSTAR)
		wrange[1] = qheight - 1;
	else if (wrange[1] == EMARK_WRANGNO)
		wrange[1] = wrange[0];
	else if (wrange[1] == EMARK_WRANGLAST)
		wrange[1] = qheight - 1;
	if (wrange[0] == EMARK_WRANGLAST)
		wrange[0] = qheight - 1;
	if (wrange[0] >= qheight || (wrange[0] < 0 && wrange[0] != EMARK_WRANGSTAR)
	|| (wrange[0] > wrange[1] && wrange[1] >= 0)
	|| wrange[1] >= qheight)
	{
		while ((tok = ft_queue_get(tokq)))
			token_del(&tok);
		return (p_ebwspec(hem));
	}
	return (SUCCESS);
}

int			get_words_replace(int wrange[2], t_histemark *hem)
{
	t_tlexicon	*tlex;

	if (!(tlex = get_hist_tlex(FT_STGET)))
		return (FAILURE);
	ft_tlex_resetsrc(tlex, hem->eventsrc);
	ft_tlex_fill(tlex);
	if (is_valid_wrange(wrange, tlex->tokens, hem) == FAILURE
	|| !(hem->replace = wordq_replace(wrange, tlex, hem)))
		return (FAILURE);
	return (SUCCESS);
}
