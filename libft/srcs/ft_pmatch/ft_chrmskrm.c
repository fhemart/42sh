/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrmskrm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:31:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/06 18:47:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_chrmskrm(t_chrmsk *target, char *todel)
{
	int		i;
	int		j;

	if (!target || !todel)
		return ;
	while (*todel)
	{
		i = *todel / 32;
		j = *todel % 32;
		target->pattern[i] = (target->pattern[i] & ~(1 << j));
		todel++;
	}
}
