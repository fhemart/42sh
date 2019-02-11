/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 02:06:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static void	print_setenv(t_sh_evar *var)
{
	if (!var)
		return ;
	print_setenv(var->next);
	ft_putstr("setenv ");
	ft_putstr(var->key);
	if (!var->value)
		return ((void)ft_putchar('\n'));
	ft_putstr("=\"");
	ft_putstr(var->value);
	ft_putstr("\"\n");
}

static int	setenv_addvar(char *name, t_sh_env *env)
{
	t_sh_evar	*var;
	char		*old;

	old = name;
	parse_tilde(&name, env);
	if ((var = sh_env_update(env, name)))
		var->isexport = TRUE;
	else
	{
		if (old != name)
			ft_strdel(&name);
		ft_putendl_fd(SHELL_NAME": setenv: "FT_ENOMEM, 2);
		return (FAILURE);
	}
	if (old != name)
		ft_strdel(&name);
	return (SUCCESS);
}

static int	setenv_parse_args(char **args, t_sh_env *env)
{
	while (*args)
	{
		if (is_valid_varname(*args))
		{
			if (setenv_addvar(*args, env) == FAILURE)
				return (FAILURE);
		}
		else
			setenv_envid(*args);
		args++;
	}
	return (SUCCESS);
}

static int	setenv_optaction(t_optdata *opt_data, t_checkopt_inf *info)
{
	int		shift;

	shift = ft_chr2index(info->msk, opt_data->optret);
	if (opt_data->optret == '?')
	{
		print_bad_opt("setenv", opt_data->optopt);
		usage_error(SETENV_USAGE);
		return (ST_FAILURE);
	}
	info->flags |= (1 << shift);
	return (ST_CONTINUE);
}

int			builtin_setenv(t_cookedcmd *cmd, t_shdata *data)
{
	t_checkopt_inf	coptinf;
	char			**args;
	int				ret;
	t_setenvsave	info;

	get_env_info(&info, data);
	args = cmd->argv + 1;
	if (!*args)
		return (usage_error(SETENV_USAGE));
	init_coptinf(&coptinf, "p", NULL, setenv_optaction);
	if ((ret = check_opt(cmd->argc - 1, args, GETOPT_SNEG, &coptinf)) == -1)
		return (EXIT_FAILURE);
	args += ret;
	if ((coptinf.flags & (1 << 0)))
		print_setenv(data->env->var);
	else if (setenv_parse_args(args, data->env) == FAILURE)
		return (EXIT_FAILURE);
	check_env_info_update(&info, data);
	return (EXIT_SUCCESS);
}
