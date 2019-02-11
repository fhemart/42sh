/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:42:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/04 17:22:37 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			init_shell_data(t_shdata *shdata, int ac, char **av, char **env)
{
	if (init_shell_env(&shdata->env, env) == FAILURE
	|| init_shell_info(shdata) == FAILURE
	|| init_shell_history(shdata) == FAILURE)
	{
		shdata_destroy(shdata);
		return (FAILURE);
	}
	shdata->opts = SET_EMACS | SET_HISTEXP;
	shdata->argc = ac;
	shdata->argv = av;
	shdata->pid = getpid();
	if (isatty(2))
		shdata->is_fork |= PRINT_PS;
	ft_bzero(&shdata->last_sub, sizeof(t_sub));
	load_builtins(&shdata->builtins);
	return (SUCCESS);
}
