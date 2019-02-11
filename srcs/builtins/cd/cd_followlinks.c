/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_followlinks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:15:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 16:45:28 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static t_bool	is_link(char *file)
{
	struct stat		st_stat;

	return (lstat(file, &st_stat) != -1 && (st_stat.st_mode & S_IFLNK) != 0);
}

static int		parse_link(char *path, size_t curr_len)
{
	char	rd_lnk[_POSIX_PATH_MAX];
	int		ret;

	if ((ret = readlink(path, rd_lnk, _POSIX_PATH_MAX - 1)) == -1)
		return (-4);
	rd_lnk[ret] = '\0';
	if (path[(curr_len > 0 ? curr_len - 1 : 0)] != '/')
		path[curr_len++] = '/';
	path[curr_len] = '\0';
	ret = follow_links(path, curr_len, rd_lnk);
	return (ret);
}

static int		copy_folder_to_path(char *path, size_t curr_len, char *folder)
{
	size_t	len;
	int		ret;

	parse_dots(path, TRUE);
	curr_len = ft_strlen(path);
	len = curr_len;
	path[len++] = '/';
	while (*folder && *folder != '/')
		path[len++] = *folder++;
	path[len] = '\0';
	if ((ret = is_directory(path)) == 0)
	{
		if (is_link(path))
			ret = parse_link(path, curr_len);
	}
	else
		return (ret);
	return (len);
}

int				parse_dots(char *path, t_bool lookbefore)
{
	t_list		*folders;
	char		*tmp;

	tmp = path;
	while (lookbefore)
	{
		if (!(tmp = ft_strchr(tmp, '.')))
			return (SUCCESS);
		if (is_dotdot(tmp))
			break ;
	}
	if (!(folders = ft_strsplit_lst(path, '/')))
		return (FAILURE);
	if (!(folders = next_valid_folder(folders)))
		*(short*)path = *(short*)"/";
	else
		list_to_path(path, folders);
	return (SUCCESS);
}

int				follow_links(char *buff, size_t curr_len, char *tofollow)
{
	int			cpy_ret;

	while (tofollow)
	{
		if (*tofollow == '/')
			tofollow++;
		cpy_ret = copy_folder_to_path(buff, curr_len, tofollow);
		tofollow = ft_strchr(tofollow, '/');
		if (cpy_ret < 0)
			return (cpy_ret);
		curr_len = cpy_ret;
	}
	return (cpy_ret);
}
