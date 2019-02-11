/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unalias.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 15:47:27 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static int	varkey_rm(t_varkey **head, t_varkey *prev, t_varkey *todel)
{
	t_varkey	*next;

	next = todel->next;
	varkey_del(&todel);
	if (prev)
		prev->next = next;
	else
		*head = next;
	return (SUCCESS);
}

static int	varkey_find_rm(t_varkey **varlist, char *key)
{
	t_varkey	*prev;
	t_varkey	*dummy;
	t_bool		found;

	if (!(dummy = *varlist))
		return (FAILURE);
	found = FALSE;
	prev = NULL;
	while (dummy)
	{
		if (ft_strequ(dummy->key, key))
		{
			found = TRUE;
			break ;
		}
		prev = dummy;
		dummy = dummy->next;
	}
	return (found ? varkey_rm(varlist, prev, dummy) : FAILURE);
}

static int	unalias_optaction(t_optdata *opt_data, t_checkopt_inf *info)
{
	int		shift;

	shift = ft_chr2index(info->msk, opt_data->optret);
	if (opt_data->optret == '?')
	{
		if (opt_data->optopt == '\0')
		{
			opt_data->optind--;
			return (ST_SUCCESS);
		}
		print_bad_opt("unalias", opt_data->optopt);
		usage_error(UNALIAS_USAGE);
		return (ST_FAILURE);
	}
	info->flags |= (1 << shift);
	return (ST_CONTINUE);
}

static int	remove_aliases(char **argv, t_shdata *data)
{
	char		*arg;
	int			ret;

	ret = EXIT_SUCCESS;
	while ((arg = *argv))
	{
		if (varkey_find_rm(&data->aliases, arg) == FAILURE)
		{
			p_enotf(SHELL_NAME": unalias: ", arg);
			ret = EXIT_FAILURE;
		}
		argv++;
	}
	return (ret);
}

int			builtin_unalias(t_cookedcmd *cmd, t_shdata *shdata)
{
	t_checkopt_inf	coptinf;
	char			**args;
	int				ret;

	g_last_signal = 0;
	signal(SIGPIPE, pipe_sig);
	args = cmd->argv + 1;
	init_coptinf(&coptinf, "a", NULL, unalias_optaction);
	if ((ret = check_opt(cmd->argc - 1, args, GETOPT_SNEG, &coptinf)) == -1)
		return (EXIT_FAILURE);
	if ((coptinf.flags & (1 << 0)))
	{
		destroy_alias(shdata->aliases);
		shdata->aliases = NULL;
		ret = EXIT_SUCCESS;
	}
	else
		ret = remove_aliases(args, shdata);
	return (ret);
}
