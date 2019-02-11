/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_histexpand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:39:05 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 17:50:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	replace_hat2emark(char **line, char **hat)
{
	char	*hpos;
	char	*find[2];
	t_lstr	*lstr;
	size_t	len;

	*hat += 1;
	lstr = NULL;
	if (!(find[0] = ft_strchr(*hat, '^'))
	|| !(find[1] = ft_strchr(find[0] + 1, '^')))
		return (FAILURE);
	hpos = *hat;
	hpos[-1] = '\0';
	ft__strcat(&lstr, *line);
	ft__strcat(&lstr, "!!:s/");
	*find[0] = '/';
	*find[1] = '/';
	ft__strcat(&lstr, hpos);
	len = ft_strlen(*line);
	ft_strdel(line);
	*line = ft_lstr_tostring(lstr);
	ft_lstrdel(&lstr);
	*hat = (*line) + len;
	return (SUCCESS);
}

static void	hist_emark_init(t_histemark *hem, char *emarkstr, char **line)
{
	t_emarkmod	*mods;

	ft_bzero(hem, sizeof(*hem));
	hem->line = line;
	hem->endmsk = new_chrmsk(HISTEMARKEND_MSK);
	hem->strbegin = emarkstr;
	hem->strend = emarkstr + 1;
	ft_bzero((mods = &hem->modifiers), sizeof(*mods));
	mods->state = ST_CONTINUE;
}

static void	remove_last_strline(char **line, t_prompt *prompt)
{
	t_list		*torm;

	ft_strdel(line);
	torm = prompt->str_line;
	prompt->str_line = torm->next;
	ft_lstdelone(&torm, ft_memdel);
	if (prompt->sline_iter)
		prompt->sline_iter--;
}

static int	hist_process_emark(t_shdata *data, t_prompt *prpt, \
							char **emarkstr, char **line)
{
	t_histemark		hem;

	hist_emark_init(&hem, *emarkstr, line);
	if (get_event(&hem, hem.strend, data) == FAILURE
	|| get_words(&hem, data) == FAILURE
	|| get_modifiers(&hem, &hem.modifiers, data) == FAILURE
	|| update_line(&hem, prpt, line, data) == FAILURE)
	{
		if (hem.eventsrc != hem.replace)
			ft_strdel(&hem.replace);
		ft_strdel(&hem.eventsrc);
		return (FAILURE);
	}
	*emarkstr = hem.strend;
	data->donotexec = hem.donotexec;
	return (SUCCESS);
}

int			get_histexpand(t_shdata *data, t_prompt *prompt, char **line)
{
	t_chrmsk	msk;
	char		*emark;

	msk = new_chrmsk("^!");
	emark = *line;
	while ((emark = chrmsk_getnext_match(emark, &msk)))
	{
		if (*emark == '^' && replace_hat2emark(line, &emark) == FAILURE)
			continue ;
		if (hist_process_emark(data, prompt, &emark, line) == FAILURE)
		{
			remove_last_strline(line, prompt);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
