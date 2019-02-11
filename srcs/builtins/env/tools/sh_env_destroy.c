/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/07 20:45:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

void		sh_evar_recdel(t_sh_evar *var)
{
	if (!var)
		return ;
	sh_evar_recdel(var->next);
	sh_evar_delone(&var);
}

void		sh_env_destroy(t_sh_env **env)
{
	t_sh_env	*dummy;

	if (!(dummy = *env))
		return ;
	sh_evar_recdel(dummy->var);
	free(dummy);
	*env = NULL;
}
