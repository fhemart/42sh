/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:20:57 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 16:34:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

t_bool		is_dotdot(char *path)
{
	if (path[0] == '.' && ((path[1] == '\0' || path[1] == '/')
	|| (path[1] == '.' && (path[2] == '\0' || path[2] == '/'))))
		return (TRUE);
	return (FALSE);
}

int			is_directory(char *dir)
{
	struct stat		st_stat;
	DIR				*directory;
	int				ret;

	ret = 0;
	if (lstat(dir, &st_stat) == -1)
		ret = -1;
	else
	{
		if (!S_ISDIR(st_stat.st_mode))
		{
			if (!(directory = opendir(dir)))
				ret = -2;
			else
				closedir(directory);
		}
		if (access(dir, X_OK | R_OK) == -1)
			ret = -3;
	}
	return (ret);
}
