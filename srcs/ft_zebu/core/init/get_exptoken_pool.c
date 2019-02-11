/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exptoken_pool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:52:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/07 11:09:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_pool		*get_exptoken_pool(int gsd)
{
	static t_pool	*etokpool;

	if (gsd != FT_STDEL)
	{
		if (!etokpool)
		{
			if (!(etokpool = ft_pool_new(20, sizeof(t_exptoken))))
				return (NULL);
		}
		if (gsd == FT_STSET)
			ft_pool_clear(etokpool);
	}
	else if (etokpool)
		ft_pool_close(&etokpool);
	return (etokpool);
}
