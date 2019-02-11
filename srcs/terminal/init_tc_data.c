/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tc_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:09:49 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/17 22:32:11 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			init_tc_data(t_shdata *ftsh, char **env)
{
	if (!(ftsh->books = gsd_books(FT_STSET, ftsh->info.path, ftsh->builtins)))
		return (FAILURE);
	ftsh->controls = get_emacs_controls();
	if (init_tc(&ftsh->term, env) == FAILURE)
		return (FAILURE);
	if (ftsh->term->mode == 0)
	{
		ftsh->term->mode = 1;
		ftsh->opts |= SET_GNL;
		return (SUCCESS);
	}
	return (SUCCESS);
}
