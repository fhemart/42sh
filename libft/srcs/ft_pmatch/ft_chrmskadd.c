/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrmskadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:31:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/21 00:40:26 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_chrmskadd(t_chrmsk *target, char *add)
{
	int		i;
	int		j;

	if (!target || !add)
		return ;
	while (*add)
	{
		i = *add / 32;
		j = *add % 32;
		if (!(target->pattern[i] & (1 << j)))
			target->pattern[i] |= (1 << j);
		add++;
	}
}
