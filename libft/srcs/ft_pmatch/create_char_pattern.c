/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_char_pattern.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 03:54:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 04:06:35 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chrmsk	new_chrmsk(char *pattern)
{
	t_chrmsk	ret;
	int			i;
	int			j;

	ft_bzero(&ret, sizeof(ret));
	while (*pattern)
	{
		if (*pattern < 0)
			continue ;
		i = *pattern % 32;
		j = *pattern / 32;
		if (!(ret.pattern[j] & (1 << i)))
			ret.pattern[j] |= (1 << i);
		pattern++;
	}
	return (ret);
}
