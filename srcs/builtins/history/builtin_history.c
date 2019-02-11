/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:50:33 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			print_ehistoor(int pos)
{
	ft_putstr_fd(SHELL_NAME": history: ", 2);
	ft_putnbr_fd(pos, 2);
	ft_putstr_fd(": "HIST_ECNFLCT"\n", 2);
	return (EXIT_FAILURE);
}

static int	hist_doactions(t_checkopt_inf *coptinf, int optret, \
							t_cookedcmd *cmd, t_shdata *shdata)
{
	static int	(*hist_act[9])() = {hist_no, hist_c, hist_d, hist_a, hist_n, \
									hist_r, hist_w, hist_p, hist_s};
	char		*arg;
	int			flag;

	if ((flag = coptinf->flags))
		flag = flag2index(flag) + 1;
	if (flag > 6)
		return (hist_act[flag](optret, cmd, shdata));
	else if (flag != 2 || (!*(arg = coptinf->custom) && optret < cmd->argc))
		arg = cmd->argv[optret + 1];
	return (hist_act[flag](arg, shdata));
}

int			builtin_history(t_cookedcmd *cmd, t_shdata *shdata)
{
	t_checkopt_inf	coptinf;
	char			**args;
	int				optret;

	(void)shdata;
	signal(SIGPIPE, pipe_sig);
	init_coptinf(&coptinf, "cdanrwps", NULL, hist_optaction);
	args = cmd->argv + 1;
	if ((optret = check_opt(cmd->argc - 1, args, GETOPT_SNEG, &coptinf)) == -1)
		return (EXIT_FAILURE);
	hist_doactions(&coptinf, optret, cmd, shdata);
	return (EXIT_SUCCESS);
}
