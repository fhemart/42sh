/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_need_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:58:38 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 17:54:52 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

t_bool				builtin_need_help(char **argv)
{
	char	*str;
	int		i;

	i = -1;
	while ((str = argv[++i]) && *str == '-')
	{
		if (str[1] == '-')
		{
			if (str[2] == '\0')
				break ;
			if (ft_strequ(str + 2, "help") == TRUE)
				return (TRUE);
		}
	}
	return (FALSE);
}
