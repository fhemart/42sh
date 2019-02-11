/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys_browsedir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:24:54 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 02:41:07 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			load_prefix(char *dname, char *fn)
{
	int				len;

	len = ft_strlen(dname);
	if (len >= FILENAME_MAX - 1)
		return (WALK_NAMETOOLONG);
	ft_strcpy(fn, dname);
	fn[len++] = '/';
	return (WALK_OK);
}

static int			check_stat(char *fn, int res)
{
	struct stat		st;

	if (lstat(fn, &st) == -1)
		res = WALK_BADIO;
	return (res);
}

int					ft_browse_dir(char *dname, int (*fptr)(), void *data, \
									void *(*fnewcontent)())
{
	struct dirent	*dent;
	DIR				*dir;
	char			fn[FILENAME_MAX];
	int				res;

	if ((res = load_prefix(dname, fn)) != WALK_OK)
		return (res);
	if (!(dir = opendir(dname)))
		return (WALK_BADIO);
	while ((dent = readdir(dir)))
	{
		if (!strcmp(dent->d_name, ".") || !ft_strcmp(dent->d_name, ".."))
			continue ;
		ft_strncpy(fn + (ft_strlen(dname) + 1), dent->d_name, \
					FILENAME_MAX - (ft_strlen(dname) + 1));
		res = check_stat(fn, res);
		if (fnewcontent)
			fptr(fn, dent->d_name, data, fnewcontent);
		else
			fptr((void*)fn, (void*)dent->d_name, data);
	}
	if (dir)
		closedir(dir);
	return (res);
}
