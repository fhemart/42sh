/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 20:07:46 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			env_print(t_sh_evar *var, char endl)
{
	if (!var)
		return (SUCCESS);
	if (env_print(var->next, endl) == FAILURE)
		return (FAILURE);
	if (!var->value || !var->isexport)
		return (SUCCESS);
	if (ft_putstr(var->key) == FAILURE
	|| ft_putchar('=') == FAILURE
	|| ft_putstr(var->value) == FAILURE
	|| ft_putchar(endl) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int			env_optaction(t_optdata *opt_data, t_checkopt_inf *info)
{
	int		shift;

	shift = ft_chr2index(info->msk, opt_data->optret);
	if (opt_data->optret == '?')
	{
		if (opt_data->optopt == '\0')
			shift = 0;
		else
		{
			opt_data->optind--;
			return (ST_SUCCESS);
		}
	}
	info->flags |= (1 << shift);
	return (ST_CONTINUE);
}

static void	env_update_evar(t_sh_evar **var, char *arg)
{
	t_sh_evar		*new_evar;
	char			*temeupeuh;
	size_t			klen;

	temeupeuh = ft_strchr(arg, '=');
	klen = temeupeuh - arg;
	if (!(new_evar = sh_evar_getkey(*var, arg, klen)))
	{
		if ((new_evar = sh_evar_fromstring(arg)))
			new_evar->isexport = TRUE;
		sh_evar_addkey(var, new_evar);
	}
	else
	{
		ft_strdel(&new_evar->value);
		new_evar->value = ft_strdup(arg + klen + 1);
	}
}

t_sh_evar	*env_parse_argv(t_cookedcmd *cmd, int opt_env, int *status)
{
	t_sh_evar		*var;
	char			**args;
	char			*arg;
	int				argc;

	args = cmd->argv;
	argc = cmd->argc;
	var = opt_env & (1 << 0) ? NULL : sh_evar_lstdup(cmd->env_var);
	while ((arg = *args))
	{
		if (is_valid_varname(arg) == FALSE || !ft_strchr(arg, '='))
		{
			*status = ENV_EXEC;
			cmd->argv = args;
			break ;
		}
		env_update_evar(&var, arg);
		args++;
		argc--;
	}
	cmd->argc = argc;
	cmd->env_var = var;
	return (var);
}

int			exec_env(t_envsave *save, t_cookedcmd *cmd, int opt, t_shdata *data)
{
	int			oldtype;
	t_list		*lst;
	char		*path;

	(void)save;
	oldtype = cmd->type;
	if (opt & (1 << 1))
	{
		ft_putstr_fd(SHELL_NAME": "ENV_ERR_DZERO, 2);
		ft_putstr_fd(ENV_USAGE"\n", 2);
		return (EXIT_FAILURE);
	}
	if (!(path = sh_env_getvalue3(cmd->env_var, "PATH")))
		path = sh_env_getvalue3(data->env->var, "PATH");
	lst = lst_from_var(path);
	data->info.home = sh_env_getvalue3(cmd->env_var, "PATH");
	parse_htbin(data->books->hashtable, lst);
	data->env->var = cmd->env_var;
	if ((cmd->type = get_cmdtype(cmd, data, "env: ")) != -1)
		ft_exec_cookedcmd(cmd, data);
	cmd->type = oldtype;
	ft_lstdel(&lst, ft_memdel);
	return (EXIT_SUCCESS);
}
