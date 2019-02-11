/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr2index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:09:49 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 22:33:48 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chr2index(char *str, char c)
{
	int				i;

	i = 0;
	while (42)
	{
		if (c == str[i])
			return (i);
		else if (!str[i])
			break ;
		i++;
	}
	return (-1);
}
