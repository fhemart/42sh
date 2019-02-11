/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_movefw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:36:43 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:36:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi_movefw(char **line)
{
	int		ret;
	char	*str;

	str = *line;
	ret = ft_atoi(str);
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	*line = str;
	return (ret);
}
