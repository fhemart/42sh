/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec_ret.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/17 17:03:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static t_bool	is_stopped(int sig)
{
	if (sig >= 19 && sig <= 22)
		return (TRUE);
	return (FALSE);
}

static void		print_sigmessage(int sig, t_cookedcmd *cmd, pid_t pid)
{
	static char		*msg[SIGMSG_COUNT] = { SIGMSG_REPACK };

	if (sig == 32 || sig == 33 || sig < 0)
	{
		ft_putstr_fd(SIG_UNKNOWN, 2);
		ft_putendl_fd(ft_static_itoa(sig), 2);
	}
	else if (sig > 33)
	{
		ft_putstr_fd(SIG_RTN, 2);
		ft_putendl_fd(ft_static_itoa(sig - 34), 2);
	}
	else if (is_stopped(sig))
	{
		ft_putchar_fd('[', 2);
		ft_putstr_fd(ft_static_itoa(pid), 2);
		ft_putstr_fd("]+  Stopped                 ", 2);
		ft_putendl_fd(cmd->argv[0], 2);
	}
	else
		ft_putstr_fd(msg[sig], 2);
}

int				parse_exec_ret(int value, t_cookedcmd *cmd, pid_t pid)
{
	int		ret;

	ret = 0;
	if (WIFSIGNALED(value))
	{
		ret = (WTERMSIG(value)) + 128;
		print_sigmessage(WTERMSIG(value), cmd, pid);
	}
	else if (WIFEXITED(value))
		ret = WEXITSTATUS(value);
	return (ret);
}
