/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_list_to_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 16:45:15 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "builtins_private.h"

static void		remove_next_valid(t_list **folders)
{
	t_list	*dummy;
	t_list	*prev;

	if (!(dummy = *folders))
		return ;
	prev = NULL;
	while (dummy && (ft_strequ(dummy->content, "..")
				|| ft_strequ(dummy->content, ".")))
	{
		prev = dummy;
		dummy = dummy->next;
	}
	if (!dummy)
		return ;
	if (prev)
		prev->next = dummy->next;
	else
		*folders = dummy->next;
	ft_lstdelone(&dummy, ft_memdel);
}

static t_list	*remove_dotdot(t_list *folders)
{
	t_list	*ret;

	if ((ret = folders->next))
		remove_next_valid(&ret);
	ft_lstdelone(&folders, ft_memdel);
	return (next_valid_folder(ret));
}

t_list			*remove_dot(t_list *folders)
{
	t_list	*ret;

	ret = folders->next;
	ft_lstdelone(&folders, ft_memdel);
	return (next_valid_folder(ret));
}

t_list			*next_valid_folder(t_list *folders)
{
	if (!folders)
		return (NULL);
	if (ft_strequ(folders->content, "."))
		return (remove_dot(folders));
	else if (ft_strequ(folders->content, ".."))
		return (remove_dotdot(folders));
	folders->next = next_valid_folder(folders->next);
	return (folders);
}

char			*list_to_path(char *path, t_list *folders)
{
	*path = '\0';
	if (!folders)
		return (path);
	path = list_to_path(path, folders->next);
	*path++ = '/';
	ft_strcpy(path, folders->content);
	path += folders->content_size;
	ft_lstdelone(&folders, ft_memdel);
	return (path);
}
