/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:58:38 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/12 22:46:39 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			get_builtin(t_builtin *builtins, char *name)
{
	int			i;

	i = -1;
	while (++i < BUILTINS_COUNT)
	{
		if (ft_strequ(builtins[i].name, name))
			return (i);
	}
	return (NOT_BUILTIN);
}
