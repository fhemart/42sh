/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 22:26:26 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static inline void	init_lvflags(int *lvflags)
{
	lvflags[0] = 0;
	lvflags[1] = 0;
}

static inline void	update_lvflags(int *lvflags, int optind, int flags)
{
	if (lvflags[1] == optind - 1)
		return ;
	lvflags[0] = flags;
	lvflags[1]++;
}

static int			echo_optaction(t_optdata *opt_data, t_checkopt_inf *info)
{
	int		shift;
	int		*lvflags;

	lvflags = info->custom;
	if ((shift = ft_chr2index(info->msk, opt_data->optret)) == -1)
	{
		update_lvflags(lvflags, opt_data->optind, info->flags);
		info->flags = lvflags[0];
		opt_data->optind--;
		return (ST_SUCCESS);
	}
	update_lvflags(lvflags, opt_data->optind, info->flags);
	info->flags |= (1 << shift);
	return (ST_CONTINUE);
}

int					builtin_echo(t_cookedcmd *cmd, t_shdata *shdata)
{
	t_checkopt_inf	coptinf;
	int				lvflags[2];
	char			**args;
	int				ret;

	(void)shdata;
	g_last_signal = 0;
	signal(SIGPIPE, pipe_sig);
	init_lvflags(lvflags);
	init_coptinf(&coptinf, "ne", lvflags, echo_optaction);
	args = cmd->argv + 1;
	ret = check_opt(cmd->argc - 1, args, GETOPT_SNEG, &coptinf);
	args += ret;
	(coptinf.flags & (1 << 1)) ? print_param_bs(args) : print_param(args);
	if (!(coptinf.flags & (1 << 0)) && ft_putchar('\n') == FAILURE)
		return (ft_write_error(SHELL_NAME": echo: "));
	return (SUCCESS);
}
