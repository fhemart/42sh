/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_options_p2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:46:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			hist_no(char *param, t_shdata *shdata)
{
	int		line_to_print;
	int		errcode;
	char	*tformat;

	(void)shdata;
	if (!param)
		line_to_print = -1;
	else
	{
		line_to_print = ft_strtoll(param, &errcode);
		if (errcode)
			return (p_enonum(SHELL_NAME": history: ", param));
		if (line_to_print < 0)
			line_to_print = -line_to_print;
	}
	tformat = sh_env_getvalue(shdata->env, "HISTTIMEFORMAT");
	hist_print_nentry(shdata->history, line_to_print, tformat);
	return (EXIT_SUCCESS);
}

int			hist_c(char *param, t_shdata *shdata)
{
	(void)param;
	hist_del_allentries(&shdata->history->entries);
	shdata->history->entry_count = 0;
	return (EXIT_SUCCESS);
}

int			hist_d(char *param, t_shdata *shdata)
{
	int			line_to_del;
	int			errcode;

	if (!param || !*param)
		return (p_eargreq(SHELL_NAME": history: ", HIST_USAGE, 'd'));
	line_to_del = ft_strtoll(param, &errcode);
	if (errcode)
		return (p_enonum(SHELL_NAME": history: ", param));
	if (hist_del_entryat(shdata->history, line_to_del) == FAILURE)
		return (print_ehistoor(line_to_del));
	return (EXIT_SUCCESS);
}

int			hist_a(char *param, t_shdata *shdata)
{
	if (!param && !(param = sh_env_getvalue(shdata->env, "HISTFILE")))
		hist_append_entries(shdata->history, param);
	else
		hist_append_entries(shdata->history, "./"DEFAULT_HISTFILE);
	hist_clamp_maxentries(shdata);
	return (EXIT_SUCCESS);
}
