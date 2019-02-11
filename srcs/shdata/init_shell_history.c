/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:42:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 14:02:53 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			init_shell_history(t_shdata *shdata)
{
	char	*histfile;

	if ((histfile = sh_env_getvalue(shdata->env, "HISTFILE")))
	{
		if (!(shdata->history = hist_new(histfile)))
			return (FAILURE);
	}
	else if (!(shdata->history = hist_new("./"DEFAULT_HISTFILE)))
		return (FAILURE);
	return (SUCCESS);
}
