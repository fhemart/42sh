/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_evar_toarraystring.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/23 18:12:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

static size_t	get_vlist_height(t_sh_evar *varlist)
{
	size_t	ret;

	ret = 0;
	while (varlist)
	{
		if (varlist->isexport)
			ret++;
		varlist = varlist->next;
	}
	return (ret);
}

static char		**cancel_evar2as(char **todel, size_t vlheight, size_t i)
{
	while (i--)
		ft_strdel(&todel[vlheight - i]);
	free(todel);
	return (NULL);
}

char			**sh_evar_toarraystring(t_sh_evar *varlist)
{
	char	**ret;
	size_t	vlheight;
	size_t	i;

	vlheight = get_vlist_height(varlist);
	if (!(ret = ft_arstrnew(vlheight)))
		return (NULL);
	i = 0;
	while (vlheight - i)
	{
		if (varlist->isexport)
			if (!(ret[vlheight - ++i] = sh_evar_tostring(varlist)))
				return (cancel_evar2as(ret, vlheight, i));
		varlist = varlist->next;
	}
	return (ret);
}
