/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/15 14:00:57 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "shell_env.h"

int			update_pwd(t_sh_env *st_env)
{
	char		cwd[PATH_MAX];

	if (!getcwd(cwd, PATH_MAX)
	|| sh_env_update2(st_env, "PWD", cwd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
