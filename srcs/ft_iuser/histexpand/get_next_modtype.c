/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_modtype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 17:40:14 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static char		*get_modsubs_word(t_histemark *hem)
{
	char	*start;
	char	*end;

	if (*(start = hem->strend) != '/'
	|| !(end = ft_strchr(++start, '/')))
	{
		hem->strend--;
		return (NULL);
	}
	hem->strend = end;
	return (ft_strndup(start, end - start));
}

static int		repeat_lastsub(t_histemark *hem, t_emarkmod *mod, \
								t_shdata *data, int mtype)
{
	t_sub		*last_sub;

	last_sub = &data->last_sub;
	if (!(mod->search = last_sub->search)
	|| !(mod->replace = last_sub->replace))
		return (p_enopsub());
	mod->type = mtype;
	hem->strend++;
	return (ST_CONTINUE);
}

static int		get_modsubs_info(t_histemark *hem, t_emarkmod *mod, \
								t_shdata *data)
{
	t_sub		*last_sub;

	if (*hem->strend++ == '&')
		return (repeat_lastsub(hem, mod, data, mod->type));
	if (!(mod->search = get_modsubs_word(hem)))
		return (p_emsubfail(hem));
	if (!(mod->replace = get_modsubs_word(hem)))
	{
		ft_strdel(&mod->search);
		return (p_emsubfail(hem));
	}
	last_sub = &data->last_sub;
	ft_strdel(&last_sub->search);
	ft_strdel(&last_sub->replace);
	last_sub->search = mod->search;
	last_sub->replace = mod->replace;
	hem->strend++;
	return (ST_CONTINUE);
}

static int		glob_err(char mod)
{
	p_emodnf(mod);
	return (ST_FAILURE);
}

int				get_next_modtype(t_histemark *hem, t_emarkmod *mod, \
								t_chrmsk *modmsk, t_shdata *data)
{
	char	c;
	int		i;

	if (*(hem->substart = hem->strend) != ':')
		return (ST_SUCCESS);
	if ((c = *(++hem->strend)) == '&')
		return (repeat_lastsub(hem, mod, data, MOD_SUBS));
	if (char_match_pattern(c, modmsk) == FALSE)
	{
		p_emodnf(*hem->strend);
		return (ST_FAILURE);
	}
	if ((i = ft_chr2index(HISTEMARK_MOD_MSK, c)) >= HISTEMARK_MOD_GLOB)
	{
		if (i == HISTEMARK_MOD_GMAX)
			i--;
		if (*(++hem->strend) != 's' && *hem->strend != '&')
			return (glob_err(*hem->strend));
		mod->type = (1 << i) | MOD_SUBS;
		return (get_modsubs_info(hem, mod, data));
	}
	else if ((mod->type = (1 << i)) == MOD_SUBS)
		return (get_modsubs_info(hem, mod, data));
	hem->strend++;
	return (ST_CONTINUE);
}
