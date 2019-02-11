/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 13:48:29 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			save_stdio(int *stdfd)
{
	int				i;
	int				j;
	struct stat		stats;

	i = -1;
	j = 3;
	while (++i < 3)
	{
		if (fstat(i, &stats) != -1)
		{
			while (fstat(j, &stats) != -1)
				j++;
			if (dup2(i, j) == -1)
				return (FAILURE);
			else
				stdfd[i] = j;
		}
		else
			stdfd[i] = -1;
	}
	return (SUCCESS);
}

void		close_saved_stdio(t_shdata *shdata)
{
	int *stdio;

	stdio = shdata->save_stdio;
	protected_close(stdio[0]);
	protected_close(stdio[1]);
	protected_close(stdio[2]);
}

int			restore_stdio(int *stdfd)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		if ((dup2(stdfd[i], i)) == -1)
			return (-1);
		close(stdfd[i]);
	}
	return (0);
}
