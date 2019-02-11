/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_varname.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/20 12:17:07 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

t_bool		is_valid_chr(char c)
{
	return (ft_isalnum(c) || c == '_');
}

t_bool		is_valid_firstchr(char c)
{
	if ((c == '=' || ft_isdigit(c)))
		return (FALSE);
	return (ft_isalpha(c) || c == '_');
}

t_bool		is_valid_varname(char *name)
{
	char	c;

	if (!is_valid_firstchr(*name))
		return (FALSE);
	name++;
	while ((c = *name) && c != '=')
	{
		if (!ft_isalnum(c) && c != '_')
			return (FALSE);
		name++;
	}
	return (TRUE);
}

t_bool		is_valid_varname2(char *name, size_t nlen)
{
	char	c;

	if (!is_valid_firstchr(*name))
		return (FALSE);
	while (--nlen && (c = *name) && c != '=')
	{
		if (!ft_isalnum(c) && c != '_')
			return (FALSE);
		name++;
	}
	return (TRUE);
}
