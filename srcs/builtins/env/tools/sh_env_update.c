/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 02:06:34 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

static inline t_sh_evar	*novalue_mode(t_sh_env *env, char *kval)
{
	t_sh_evar	*var;

	var = sh_evar_getkey(env->var, kval, ft_strlen(kval));
	if (!var && (var = sh_evar_new(kval, NULL)))
		sh_evar_addkey(&env->var, var);
	return (var);
}

static inline t_sh_evar	*value_mode(t_sh_env *env, size_t klen, char *kval)
{
	t_sh_evar	*var;

	if ((var = sh_evar_getkey(env->var, kval, klen)))
	{
		ft_strdel(&var->value);
		if (!(var->value = ft_strdup(kval + klen + 1)))
			return (NULL);
	}
	else if ((var = sh_evar_fromstring(kval)))
		sh_evar_addkey(&env->var, var);
	return (var);
}

int						sh_env_update2(t_sh_env *env, char *key, char *value)
{
	t_sh_evar	*var;

	if (!key || !is_valid_varname(key))
		return (FAILURE);
	if ((var = sh_evar_getkey(env->var, key, ft_strlen(key))))
	{
		if (!value)
			return (SUCCESS);
		ft_strdel(&var->value);
		if (!(var->value = ft_strdup(value)))
			return (FAILURE);
	}
	else if ((var = sh_evar_new(key, value)))
		sh_evar_addkey(&env->var, var);
	else
		return (FAILURE);
	return (SUCCESS);
}

t_sh_evar				*sh_env_update(t_sh_env *env, char *keyvalue)
{
	char		*eq;
	t_sh_evar	*var;

	if (!is_valid_varname(keyvalue))
		return (NULL);
	if ((eq = ft_strchr(keyvalue, '=')))
		var = value_mode(env, eq - keyvalue, keyvalue);
	else
		var = novalue_mode(env, keyvalue);
	return (var);
}
