/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_getvalue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 02:19:49 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

char		*sh_env_getvalue(t_sh_env *env, char *key)
{
	t_sh_evar	*var;

	if (!(var = sh_evar_getkey(env->var, key, ft_strlen(key))))
		return (NULL);
	return (var->value);
}

char		*sh_env_getvalue2(t_sh_env *env, char *key, size_t klen)
{
	t_sh_evar	*var;

	if (!(var = sh_evar_getkey(env->var, key, klen)))
		return (NULL);
	return (var->value);
}

char		*sh_env_getvalue3(t_sh_evar *vklist, char *key)
{
	t_sh_evar	*var;

	if (!(var = sh_evar_getkey(vklist, key, ft_strlen(key))))
		return (NULL);
	return (var->value);
}
