/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 18:01:42 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static int	exit_enonum(char *arg)
{
	p_enonum(SHELL_NAME": exit: ", arg);
	return (255);
}

static char	get_status(char *argv, int last_retval)
{
	long long	ret;
	int			errcode;

	if (!argv)
		return (last_retval);
	ret = ft_strtoll(argv, &errcode);
	if (!errcode)
		return (ret);
	return (exit_enonum(argv));
}

int			builtin_exit(t_cookedcmd *cmd, t_shdata *shdata)
{
	char	exit_status;

	exit_status = get_status(cmd->argv[1], shdata->last_retval);
	exit_shell(cmd, shdata, exit_status);
	return (SUCCESS);
}
