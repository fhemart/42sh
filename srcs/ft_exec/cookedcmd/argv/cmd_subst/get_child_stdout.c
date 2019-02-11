/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_child_stdout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 16:39:02 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void		suppress_ending_newlines(char *str, size_t len)
{
	while (len-- && str[len] == '\n')
		str[len] = '\0';
}

char		*get_child_stdout(int read_fd, pid_t child, t_shdata *data)
{
	t_lstr		*lstr;
	int			read_ret;
	char		tmp[128];
	char		*ret;
	int			exec_ret;

	lstr = NULL;
	while ((read_ret = read(read_fd, tmp, 127)) > 0)
	{
		tmp[read_ret] = '\0';
		lstr = ft__strcat(&lstr, tmp);
	}
	if (!lstr)
		lstr = ft__strcat(&lstr, "");
	if ((ret = ft_lstr_tostring(lstr)))
		suppress_ending_newlines(ret, ft_lstrlen(lstr));
	ft_lstrdel(&lstr);
	waitpid(child, &exec_ret, 0);
	if (read_fd != -1)
		close(read_fd);
	data->last_retval = WEXITSTATUS(exec_ret);
	return (ret);
}
