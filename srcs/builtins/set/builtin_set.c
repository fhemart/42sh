/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 18:18:33 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static void		set_flag(int flag, t_bool enable, t_shdata *data)
{
	if (enable == TRUE)
		data->opts |= (1 << flag);
	else
		data->opts &= ~(1 << flag);
	if (flag == SET_FLGSCOLOR)
		data->term->prompt->color = (data->opts & SET_SCOLOR) ? 1 : 0;
	else if (flag == SET_FLGEMACS)
	{
		if (data->opts & SET_EMACS)
			data->controls = get_emacs_controls();
		else
			data->controls = get_std_controls();
	}
}

static size_t	get_maxlen(const char **astr, int i)
{
	size_t	ret;
	size_t	len;

	ret = 0;
	while (i--)
	{
		if ((len = ft_strlen(astr[i])) > ret)
			ret = len;
	}
	return (ret);
}

static void		print_options(int options, t_shdata *data)
{
	const char		*mskstr[SET_FLGMSK_CNT] = {SET_MSKSTR};
	const int		mskvalue[SET_FLGMSK_CNT] = {SET_MSKVALUE};
	static size_t	maxlen = 0;
	size_t			len;
	int				i;

	if (!maxlen)
		maxlen = get_maxlen(mskstr, SET_FLGMSK_CNT) + 2;
	i = -1;
	while (++i < SET_FLGMSK_CNT)
	{
		len = maxlen - ft_strlen(mskstr[i]);
		if (data->opts & SET_SCOLOR)
			ft_putstr("\x1B[34m");
		ft_putstr((char*)mskstr[i]);
		while (len--)
			ft_putchar(' ');
		if (data->opts & SET_SCOLOR)
			ft_putstr((options & mskvalue[i]) ? "\x1B[32m" : "\x1B[31m");
		ft_putstr((options & mskvalue[i]) ? "yes\n" : "no\n");
	}
}

static void		applyflags(int parsedflg, t_shdata *data)
{
	int				i;

	i = -1;
	while (++i < SET_FLGMSK_CNT)
	{
		if (parsedflg & (1 << i))
			set_flag(i, TRUE, data);
		else if ((parsedflg >> 8) & (1 << i))
			set_flag(i, FALSE, data);
	}
	if (parsedflg & SET_PRINTOPT)
		print_options(data->opts, data);
}

int				builtin_set(t_cookedcmd *cmd, t_shdata *shdata)
{
	t_checkopt_inf	coptinf;
	t_argpack		argpack;
	char			**args;
	int				optret;

	(void)shdata;
	signal(SIGPIPE, pipe_sig);
	argpack = (t_argpack){cmd->argv + 1, cmd->argc - 1};
	init_coptinf(&coptinf, "eHPo", NULL, set_optaction);
	coptinf.custom = &argpack;
	if (!*(args = cmd->argv + 1))
		return (EXIT_SUCCESS);
	if (builtin_need_help(args) == TRUE)
	{
		ft_putstr(SET_USAGE"\n");
		return (EXIT_SUCCESS);
	}
	if ((optret = check_opt(cmd->argc - 1, args, GETOPT_SBOTH, &coptinf)) == -1)
		return (EXIT_FAILURE);
	applyflags(coptinf.flags, shdata);
	return (EXIT_SUCCESS);
}
