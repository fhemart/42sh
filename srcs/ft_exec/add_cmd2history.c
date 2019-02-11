/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd2history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:03:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/26 21:03:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static void	run_lst2entries(t_list *line, int histcontrol, \
							t_shhist *hist, t_shdata *data)
{
	char	*tmp;

	if (!line)
		return ;
	run_lst2entries(line->next, histcontrol, hist, data);
	tmp = line->content;
	if (tmp[line->content_size - 2] == '\n')
		tmp[line->content_size - 2] = '\0';
	if (!(((histcontrol & HC_IGNSPACE) && tmp[0] == ' ')
	|| ((histcontrol & HC_IGNDUPS)
		&& ft_strequ(tmp, hist->entries->string))))
	{
		hist_add_entry(hist, tmp);
		hist_clamp_maxentries(data);
	}
}

int			add_cmd2history(t_shdata *shdata, t_list *line)
{
	int		histcontrol;

	if (!(shdata->opts & SET_HISTORY))
		return (SUCCESS);
	histcontrol = get_histcontrol(shdata);
	run_lst2entries(line, histcontrol, shdata->history, shdata);
	return (SUCCESS);
}
