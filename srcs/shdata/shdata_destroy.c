/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdata_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:42:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 19:51:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "builtins_private.h"

static void	save_history(t_shdata *data)
{
	char	*histfile;

	if ((data->is_fork != 0 && data->is_fork != PRINT_PS)
		|| !(data->opts & SET_HISTORY))
		return ;
	if (!(histfile = sh_env_getvalue(data->env, "HISTFILE")))
		hist_append_entries(data->history, "./"DEFAULT_HISTFILE);
	else
		hist_append_entries(data->history, histfile);
}

void		shdata_destroy(t_shdata *shdata)
{
	save_history(shdata);
	hist_del(&shdata->history);
	sh_env_destroy(&shdata->env);
	del_inputlist(&shdata->command);
	close_saved_stdio(shdata);
	if (BUILTINS_COUNT && shdata->builtins)
		free(shdata->builtins);
	ft_lstdel(&shdata->info.path, ft_memdel);
	ft_lstdel(&shdata->info.cdpath, ft_memdel);
	ft_strdel(&shdata->emark_laststr);
	ft_strdel(&shdata->emark_lastneedle);
	ft_strdel(&shdata->last_sub.search);
	ft_strdel(&shdata->last_sub.replace);
	destroy_alias(shdata->aliases);
	ft_bzero(shdata, sizeof(t_shdata));
}
