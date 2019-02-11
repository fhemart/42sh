/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_pool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:52:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/07 10:56:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_pool		*get_token_pool(int gsd)
{
	static t_pool	*tokpool;

	if (gsd != FT_STDEL)
	{
		if (!tokpool)
		{
			if (!(tokpool = ft_pool_new(10, sizeof(t_token))))
				return (NULL);
		}
		if (gsd == FT_STSET)
			ft_pool_clear(tokpool);
	}
	else if (tokpool)
		ft_pool_close(&tokpool);
	return (tokpool);
}
