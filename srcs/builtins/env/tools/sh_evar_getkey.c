/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_evar_getkey.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 02:29:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

t_sh_evar	*sh_evar_getkey(t_sh_evar *varlist, char *key, size_t keylen)
{
	if (!key)
		return (NULL);
	while (varlist)
	{
		if (keylen == ft_strlen(varlist->key)
		&& ft_strnequ(varlist->key, key, keylen))
			return (varlist);
		varlist = varlist->next;
	}
	return (NULL);
}
