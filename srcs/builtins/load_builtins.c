/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:58:38 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/18 10:55:03 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			load_builtins(t_builtin **target)
{
	static char	*names[BUILTINS_COUNT] = {BUILTINS_NAME};
	static int	(*bi_f[BUILTINS_COUNT])(t_cookedcmd*, t_shdata*) = {BUILTINS_F};
	t_builtin	*builtins;
	int			i;

	if (!BUILTINS_COUNT)
		return (SUCCESS);
	if (!(builtins = (t_builtin*)malloc(BUILTINS_COUNT * sizeof(t_builtin))))
		return (FAILURE);
	i = -1;
	while (++i < BUILTINS_COUNT)
	{
		builtins[i].name = names[i];
		builtins[i].f = bi_f[i];
	}
	*target = builtins;
	return (SUCCESS);
}
