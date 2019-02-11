/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varkey_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 13:32:18 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

t_varkey	*varkey_find(char *name, t_varkey *vklist)
{
	if (!vklist)
		return (NULL);
	if (ft_strequ(name, vklist->key))
		return (vklist);
	return (varkey_find(name, vklist->next));
}

t_varkey	*varkey_find2(char *name, size_t nsize, t_varkey *vklist)
{
	if (!vklist)
		return (NULL);
	if (ft_strnequ(name, vklist->key, nsize))
		return (vklist);
	return (varkey_find2(name, nsize, vklist->next));
}

t_varkey	*alias_getvarkey(char *name, t_varkey *aliases)
{
	char	*eq;

	if (!(eq = ft_strchr(name, '=')))
		return (varkey_find(name, aliases));
	return (varkey_find2(name, eq - name, aliases));
}
