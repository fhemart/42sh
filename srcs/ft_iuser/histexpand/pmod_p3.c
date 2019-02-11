/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmod_p3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 17:27:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int		bw_replace_lstr(char **str, t_emarkmod *mods, t_lstr **lstr)
{
	char	*dummy;
	char	*find;
	char	c;

	dummy = *str;
	if (!(find = ft_strstr(dummy, mods->search)))
		return (ST_SUCCESS);
	c = *find;
	*find = '\0';
	if (!ft__strcat(lstr, dummy) || !ft__strcat(lstr, mods->replace))
		return (ST_FAILURE);
	*str = find + ft_strlen(mods->search);
	*find = c;
	return (ST_CONTINUE);
}

static int		tok_cat_and_replace(char *begend[2], char *tokstr, \
									t_emarkmod *mods, t_lstr **lstr)
{
	begend[1] = ft_strstr(begend[0], tokstr);
	*begend[1] = '\0';
	if (!ft__strcat(lstr, begend[0]))
		return (FAILURE);
	begend[0] = tokstr;
	bw_replace_lstr(&begend[0], mods, lstr);
	if (!ft__strcat(lstr, begend[0]))
		return (FAILURE);
	begend[0] = begend[1] + ft_strlen(tokstr);
	return (SUCCESS);
}

int				pmods_gw(char *str, t_histemark *hem, t_lstr *lstr, \
						t_emarkmod *mods)
{
	t_tlexicon	*tlex;
	t_token		*tok;
	char		*tokstr;
	char		*begend[2];

	if (!(tlex = get_hist_tlex(FT_STGET)))
		return (FAILURE);
	ft_tlex_resetsrc(tlex, str);
	ft_tlex_fill(tlex);
	begend[0] = str;
	while ((tok = ft_queue_get(tlex->tokens)))
	{
		if (!(tokstr = tok->content))
			tokstr = tkn_tostring(tlex->grammar, tok->type);
		tok_cat_and_replace(begend, tokstr, mods, &lstr);
		token_del(&tok);
	}
	ft__strcat(&lstr, begend[0]);
	ft_strdel(&hem->replace);
	hem->replace = ft_lstr_tostring(lstr);
	ft_lstrdel(&lstr);
	return (SUCCESS);
}

int				pmods(t_histemark *hem, t_emarkmod *mods)
{
	t_lstr	*lstr;
	char	*lastfound;

	lastfound = hem->replace;
	lstr = NULL;
	if (mods->type & MOD_GLWRD)
		return (pmods_gw(lastfound, hem, NULL, mods));
	else if (mods->type & MOD_GLOB)
		while (bw_replace_lstr(&lastfound, mods, &lstr) == ST_CONTINUE)
			;
	else
		bw_replace_lstr(&lastfound, mods, &lstr);
	ft__strcat(&lstr, lastfound);
	ft_strdel(&hem->replace);
	hem->replace = ft_lstr_tostring(lstr);
	ft_lstrdel(&lstr);
	return (ST_SUCCESS);
}
