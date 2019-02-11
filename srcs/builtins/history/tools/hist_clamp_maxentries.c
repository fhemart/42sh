/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_clamp_maxentries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:17:09 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void		hist_del_nfirstentry(t_shhist *history, int n)
{
	t_histentry	*entry;

	if (n <= 0)
		return ;
	entry = history->entries;
	while (entry->prev)
		entry = entry->prev;
	while (n--)
		hist_del_entry(&history->entry_count, &entry);
}

void		hist_clamp_maxentries(t_shdata *data)
{
	t_shhist	*history;
	char		*smaxstr;
	int			sizemax;

	history = data->history;
	if ((smaxstr = sh_env_getvalue(data->env, "HISTSIZE"))
	&& ft_strisdigit(smaxstr))
		sizemax = ft_atoi(smaxstr);
	else
		sizemax = DEFAULT_HISTSIZE;
	hist_del_nfirstentry(history, history->entry_count - sizemax);
}
