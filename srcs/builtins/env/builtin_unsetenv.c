/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 01:36:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static void	unsetenv_del_args(char **args, t_sh_env *env)
{
	char	*eq;
	size_t	klen;

	while (*args)
	{
		if (is_valid_varname(*args))
		{
			if ((eq = ft_strchr(*args, '=')))
				klen = eq - *args;
			else
				klen = ft_strlen(*args);
			if (sh_evar_delkey(&env->var, *args, klen) == FAILURE)
				unsetenv_id_doesntexist(*args);
		}
		else
			unsetenv_id_doesntexist(*args);
		args++;
	}
}

int			builtin_unsetenv(t_cookedcmd *cmd, t_shdata *data)
{
	t_setenvsave			info;

	ft_bzero(&info, sizeof(char*) * 2);
	get_env_info(&info, data);
	if (!cmd->argv[1] || *cmd->argv[1] == '-')
		return (usage_error(UNSETENV_USAGE));
	else
		unsetenv_del_args(cmd->argv + 1, data->env);
	check_env_info_update(&info, data);
	return (EXIT_SUCCESS);
}
