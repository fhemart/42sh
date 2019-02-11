/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_ifexecbin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 05:27:09 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/09 20:04:39 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "books.h"

void			tab_copypath(char *home, char *path, char *buff)
{
	if (home && *path == '~' \
		&& (!path[1] || path[1] == '/'))
	{
		ft_strcpy(buff, home);
		ft_strcat(buff, path + 1);
	}
	else
		ft_strcpy(buff, path);
}

int				tab_ifexecbin(t_tab *state, char *word)
{
	char		path[PATH_MAX];
	char		*ptr;
	int			ret;

	tab_copypath(state->shinfo->home, state->path, path);
	ft_strcat(path, "/");
	ft_strcat(path, word);
	if (path[0] == '/' && path[1] == '/')
		ptr = path + 1;
	else
		ptr = path;
	ret = isdir(ptr);
	if (ret == 1)
		return (TRUE);
	return (is_executable(ptr, FALSE, NULL, NULL));
}
