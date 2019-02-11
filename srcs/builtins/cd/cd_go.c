/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:10:41 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 16:16:31 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			cd_go_home(int flags, t_shdata *shdata)
{
	char	*path;

	if (!(path = sh_env_getvalue(shdata->env, "HOME")) || !*path)
		return (usage_error(CD_EHOME));
	return (access_folder(flags, "", path, shdata));
}

int			cd_go_oldpwd(int flags, t_shdata *shdata)
{
	char	*path;

	if (!(path = sh_env_getvalue(shdata->env, "OLDPWD")) || !*path)
		return (usage_error(CD_EOPWD));
	if (access_folder(flags, path, "", shdata) == SUCCESS)
	{
		if ((path = sh_env_getvalue(shdata->env, "PWD")))
			if (ft_putendl(path) == FAILURE)
				return (ft_write_error(SHELL_NAME": cd: "));
		return (SUCCESS);
	}
	return (FAILURE);
}
