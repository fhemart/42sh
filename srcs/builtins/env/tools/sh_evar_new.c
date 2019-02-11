/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_evar_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/15 12:04:43 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

t_sh_evar	*sh_evar_new(char *key, char *value)
{
	t_sh_evar	*new;

	if (!(new = (t_sh_evar*)ft_memalloc(sizeof(t_sh_evar))))
		return (NULL);
	new->next = NULL;
	if (!(new->key = ft_strdup(key))
	|| (value && !(new->value = ft_strdup(value))))
	{
		ft_strdel(&new->key);
		free(new);
		return (NULL);
	}
	return (new);
}
