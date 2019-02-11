/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_init_pools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:52:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/07 10:55:14 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

int			factory_init_pools(void)
{
	int		ret;

	ret = 0;
	if (!get_exptoken_pool(FT_STSET))
		ret = -1;
	if (ret == -1)
		ft_zebu_exit();
	return (ret);
}
