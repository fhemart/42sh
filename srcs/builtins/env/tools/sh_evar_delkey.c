/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_evar_delkey.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/15 19:43:29 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

int		sh_evar_delkey(t_sh_evar **varlist, char *key, size_t keylen)
{
	t_sh_evar	*found;

	if (!(found = sh_evar_getkey(*varlist, key, keylen)))
		return (FAILURE);
	sh_evar_delvar(varlist, found);
	return (SUCCESS);
}
