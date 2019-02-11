/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_blacklist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 10:29:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/05 10:30:36 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

void			reset_blacklist(t_blacklist *blacklist)
{
	int		i;

	i = -1;
	while (++i < BLACKLIST_INTSIZE)
		blacklist->mask[i] = 0;
}
