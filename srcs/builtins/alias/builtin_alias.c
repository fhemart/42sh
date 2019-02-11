/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 14:17:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static int			print_aliases(t_varkey *alias)
{
	if (!alias)
		return (SUCCESS);
	if (ft_putstr("alias ") == FAILURE
	|| varkey_print(alias) == FAILURE)
		return (FAILURE);
	return (print_aliases(alias->next));
}

static int			add_aliases(char **args, t_shdata *data)
{
	t_varkey	*new;
	char		*eq;
	char		*arg;

	while ((arg = *args))
	{
		if (!(eq = ft_strchr(arg, '=')))
		{
			if ((new = varkey_find(arg, data->aliases)))
			{
				ft_putstr("alias ");
				varkey_print(data->aliases);
			}
			else
				p_enotf(SHELL_NAME": alias: ", arg);
		}
		else
		{
			new = varkey_new(arg);
			varkey_isort(&data->aliases, new);
		}
		args++;
	}
	return (EXIT_SUCCESS);
}

static int			alias_optaction(t_optdata *opt_data, t_checkopt_inf *info)
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
		print_bad_opt("alias", opt_data->optopt);
		usage_error(ALIAS_USAGE);
		return (ST_FAILURE);
	}
	info->flags |= (1 << shift);
	return (ST_CONTINUE);
}

void				destroy_alias(t_varkey *alias)
{
	if (!alias)
		return ;
	destroy_alias(alias->next);
	varkey_del(&alias);
}

int					builtin_alias(t_cookedcmd *cmd, t_shdata *shdata)
{
	t_checkopt_inf	coptinf;
	char			**args;
	int				optret;

	g_last_signal = 0;
	signal(SIGPIPE, pipe_sig);
	args = cmd->argv + 1;
	init_coptinf(&coptinf, "p", NULL, alias_optaction);
	if ((optret = check_opt(cmd->argc - 1, args, GETOPT_SNEG, &coptinf)) == -1)
		return (EXIT_FAILURE);
	args += optret;
	if (!*args)
	{
		if (print_aliases(shdata->aliases) == FAILURE)
			return (ft_write_error(SHELL_NAME": alias: "));
	}
	else
	{
		if ((coptinf.flags & (1 << 0))
		&& print_aliases(shdata->aliases) == FAILURE)
			return (ft_write_error(SHELL_NAME": alias: "));
		add_aliases(args, shdata);
	}
	return (EXIT_SUCCESS);
}
