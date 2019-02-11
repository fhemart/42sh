/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exptoken_freshdup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:29:21 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 13:57:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

static t_exptoken	*get_from_pool(void)
{
	static t_pool	*pool;

	if (!pool && !(pool = get_exptoken_pool(FT_STGET)))
		return (NULL);
	return (ft_pool_get(pool));
}

t_exptoken			*exptoken_freshdup(t_exptoken *src)
{
	t_exptoken	*dup;

	if (!(dup = get_from_pool()))
		return (NULL);
	dup->id = src->id;
	dup->validstate = TF_UNVALIDSTATE;
	dup->maxstate = src->maxstate;
	dup->rules = src->rules;
	dup->tsoffset = src->tsoffset;
	dup->isrecursive = src->isrecursive;
	return (dup);
}
