/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 03:32:52 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static t_bool	is_valid_file(char *file)
{
	if (*file == '/' || (file[0] == '.'
	&& (!file[1] || file[1] == '/' || (file[1] == '.' && (file[2] == '/'
		|| !file[2])))))
		return (TRUE);
	return (FALSE);
}

int				is_executable(char *file, t_bool perr, \
							char *errheader, char *cmdname)
{
	struct stat		st_stat;

	if (!is_valid_file(file) || lstat(file, &st_stat) == -1)
	{
		if (perr == TRUE)
			p_enoent(cmdname, errheader);
		return (FALSE);
	}
	else if ((st_stat.st_mode & S_IFMT) == S_IFDIR)
	{
		if (perr == TRUE)
			p_eisdir(cmdname, errheader);
		return (FALSE);
	}
	if (access(file, X_OK | R_OK) != -1)
		return (TRUE);
	if (perr == TRUE)
		p_eacces(cmdname, errheader);
	return (FALSE);
}
