/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 17:01:57 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			is_escape_sequence(char c)
{
	const char		parsed_seq[] = "abeEfnrtv\\c0xuU";
	size_t			i;

	i = -1;
	while (++i < sizeof(parsed_seq))
		if (parsed_seq[i] == c)
			return ((int)i);
	return (-1);
}

int			bs_act_hex(t_awstr *awstr, char **src, int *cut)
{
	char	hex;
	char	*str;

	(void)cut;
	str = *src + 1;
	if (ft_ishexdec(*str))
	{
		hex = parse_bshex(str, src);
		ft_awstrset(awstr, hex, 1);
	}
	else
	{
		ft_awstrncat(awstr, "\\x", 2);
		*src = str;
	}
	return (0);
}
