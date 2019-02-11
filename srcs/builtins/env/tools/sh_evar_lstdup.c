/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_evar_lstdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 17:58:25 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

t_sh_evar			*sh_evar_dup(t_sh_evar *src)
{
	t_sh_evar	*new;

	if (!src || !(new = sh_evar_new(src->key, src->value)))
		return (NULL);
	new->isexport = src->isexport;
	return (new);
}

static t_sh_evar	*dup_it(t_sh_evar **target, t_sh_evar *dup)
{
	if (dup->next)
		sh_evar_addkey(target, dup_it(target, dup->next));
	return (sh_evar_dup(dup));
}

t_sh_evar			*sh_evar_lstdup(t_sh_evar *headsrc)
{
	t_sh_evar	*ret;

	if (!headsrc)
		return (NULL);
	ret = NULL;
	sh_evar_addkey(&ret, dup_it(&ret, headsrc));
	return (ret);
}
