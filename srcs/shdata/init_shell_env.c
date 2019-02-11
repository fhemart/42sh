/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 02:47:56 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

static int	update_shlvl(t_sh_env *st_env)
{
	t_sh_evar	*var;
	int			lvl;

	if ((var = sh_evar_getkey(st_env->var, "SHLVL", ft_strlen("SHLVL"))))
	{
		lvl = var->value ? ft_atoi(var->value) + 1 : 1;
		ft_strdel(&var->value);
		if (!(var->value = ft_itoa(lvl)))
			return (FAILURE);
	}
	else if ((var = sh_evar_new("SHLVL", "1")))
	{
		var->isexport = TRUE;
		sh_evar_addkey(&st_env->var, var);
	}
	else
		return (FAILURE);
	return (SUCCESS);
}

int			init_shell_env(t_sh_env **st_env, char **ar_env)
{
	t_sh_env	*dummy;

	if (!(dummy = sh_env_new(ar_env)))
		return (FAILURE);
	if (update_pwd(dummy) == FAILURE
	|| update_shlvl(dummy) == FAILURE)
	{
		sh_env_destroy(&dummy);
		return (FAILURE);
	}
	*st_env = dummy;
	return (SUCCESS);
}
