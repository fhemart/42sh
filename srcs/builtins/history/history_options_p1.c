/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_options_p1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:45:12 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			hist_n(char *param, t_shdata *shdata)
{
	if (!param && !(param = sh_env_getvalue(shdata->env, "HISTFILE")))
		hist_load_entries_nd(shdata->history, param);
	else
		hist_load_entries_nd(shdata->history, "./"DEFAULT_HISTFILE);
	hist_clamp_maxentries(shdata);
	return (EXIT_SUCCESS);
}

int			hist_r(char *param, t_shdata *shdata)
{
	if (!param && !(param = sh_env_getvalue(shdata->env, "HISTFILE")))
		hist_load_entries(shdata->history, param);
	else
		hist_load_entries(shdata->history, "./"DEFAULT_HISTFILE);
	hist_clamp_maxentries(shdata);
	return (EXIT_SUCCESS);
}

int			hist_w(char *param, t_shdata *shdata)
{
	if (!param && !(param = sh_env_getvalue(shdata->env, "HISTFILE")))
		hist_write_entries(shdata->history, param);
	else
		hist_write_entries(shdata->history, "./"DEFAULT_HISTFILE);
	hist_clamp_maxentries(shdata);
	return (EXIT_SUCCESS);
}

int			hist_p(int optret, t_cookedcmd *cmd, t_shdata *shdata)
{
	char		**argv;
	int			argc;
	t_shhist	*hist;

	hist = shdata->history;
	hist_del_entry(&hist->entry_count, &hist->entries);
	argv = cmd->argv;
	argc = cmd->argc;
	while (++optret < argc)
		ft_putendl(argv[optret]);
	return (EXIT_SUCCESS);
}

int			hist_s(int optret, t_cookedcmd *cmd, t_shdata *shdata)
{
	char	**argv;
	char	*str;
	size_t	alen;
	size_t	curr_len;
	size_t	len;

	hist_del_entry(&shdata->history->entry_count, &shdata->history->entries);
	argv = cmd->argv + optret + 1;
	alen = cmd->argc - (optret + 1);
	if (!(str = ft_strnew(ft_astrlen(argv, alen) + alen)))
		return (EXIT_FAILURE);
	curr_len = 0;
	while (alen--)
	{
		len = ft_strlen(*argv);
		ft_memcpy(str + curr_len, *argv++, len);
		curr_len += len;
		str[curr_len++] = (alen ? ' ' : '\0');
	}
	hist_add_entry(shdata->history, str);
	free(str);
	return (EXIT_SUCCESS);
}
