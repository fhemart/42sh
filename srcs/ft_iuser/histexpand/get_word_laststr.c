/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_laststr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:20:56 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				get_word_laststr(t_histemark *hem, t_shdata *data)
{
	t_tlexicon	*tlex;
	size_t		len[3];
	char		*ret;
	char		*tokstr;
	t_token		*tok;

	if (!(tlex = get_hist_tlex(FT_STGET)))
		return (FAILURE);
	len[0] = ft_strlen(data->emark_lastneedle);
	ft_tlex_resetsrc(tlex, data->emark_laststr);
	ft_tlex_fill(tlex);
	ret = NULL;
	while ((tok = ft_queue_get(tlex->tokens)))
	{
		if (!(tokstr = tok->content))
			tokstr = tkn_tostring(tlex->grammar, tok->type);
		len[1] = ft_strlen(tokstr);
		len[2] = len[0] > len[1] ? len[1] : len[0];
		if (!ret && ft_strnstr(tokstr, data->emark_lastneedle, len[2]))
			ret = ft_strdup(tokstr);
		token_del(&tok);
	}
	if (!(hem->replace = ret))
		hem->replace = ft_memalloc(1);
	return (SUCCESS);
}
