/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/07 20:45:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

t_sh_env	*sh_env_new(char **model)
{
	t_sh_env	*new;
	t_sh_evar	*var;

	if (!(new = (t_sh_env*)ft_memalloc(sizeof(t_sh_env))))
		return (NULL);
	while (*model)
	{
		var = sh_evar_fromstring(*model);
		var->isexport = TRUE;
		sh_evar_addkey(&new->var, var);
		model++;
	}
	return (new);
}
