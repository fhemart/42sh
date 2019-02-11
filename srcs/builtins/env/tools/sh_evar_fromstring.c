/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_evar_fromstring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/15 12:05:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

static t_sh_evar	*create_var_with_no_value(t_sh_evar *ret, char *str)
{
	if (!(ret->key = ft_strdup(str)))
		sh_evar_delone(&ret);
	return (ret);
}

t_sh_evar			*sh_evar_fromstring(char *str)
{
	t_sh_evar	*ret;
	char		*eq;

	if (!is_valid_varname(str)
	|| !(ret = (t_sh_evar*)ft_memalloc(sizeof(t_sh_evar))))
		return (NULL);
	if (!(eq = ft_strchr(str, '=')))
		return (create_var_with_no_value(ret, str));
	if (!(ret->key = ft_strndup(str, eq - str))
	|| !(ret->value = ft_strdup(eq + 1)))
		sh_evar_delone(&ret);
	return (ret);
}
