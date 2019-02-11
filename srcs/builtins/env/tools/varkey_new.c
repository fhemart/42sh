/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varkey_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 13:28:39 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

t_varkey	*varkey_new(char *vksrc)
{
	t_varkey	*new;
	size_t		klen;
	char		*eq;

	if (!(new = (t_varkey*)ft_memalloc(sizeof(*new))))
		return (NULL);
	if ((eq = ft_strchr(vksrc, '=')))
		klen = (size_t)(eq - vksrc);
	else
		klen = ft_strlen(vksrc);
	if (!(new->key = ft_strndup(vksrc, klen))
	|| !(new->value = ft_strdup(vksrc + klen + 1)))
		varkey_del(&new);
	return (new);
}

t_varkey	*varkey_new2(char *key, char *value)
{
	t_varkey	*new;

	if (!(new = (t_varkey*)ft_memalloc(sizeof(*new))))
		return (NULL);
	if (!(new->key = ft_strdup(key))
	|| !(new->value = ft_strdup(value)))
		varkey_del(&new);
	return (new);
}
