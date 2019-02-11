/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrmsk_getnext_match.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 02:43:39 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/25 02:51:03 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*chrmsk_getnext_match(char *src, t_chrmsk *tomatch)
{
	char	c;

	while ((c = *src))
	{
		if (char_match_pattern(c, tomatch))
			return (src);
		src++;
	}
	return (NULL);
}
