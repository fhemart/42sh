/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 16:40:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static char		*get_from_path(char *name, t_hashtable *path_hash)
{
	t_hashcontent	*hcntt;

	if (!(hcntt = ft_hashtable_get(path_hash, name)))
		return (NULL);
	return (hcntt->fullpath);
}

char			*get_command_name(t_cookedcmd *cmd, t_shdata *data, \
										char *errhead)
{
	char			*name;
	char			*curr_name;

	curr_name = cmd->argv[0];
	if (curr_name)
	{
		if (ft_strchr(curr_name, '/'))
			return (curr_name);
		else if ((name = get_from_path(curr_name, data->books->hashtable)))
			return (name);
		else
		{
			if (errhead)
				ft_putstr_fd(errhead, 2);
			ft_putstr_fd(curr_name, 2);
			ft_putstr_fd(": command not found\n", 2);
		}
		data->last_retval = 127;
	}
	return (NULL);
}
