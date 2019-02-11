/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:32:51 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/24 13:20:19 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl(char *str)
{
	if (ft_putstr(str) == FAILURE)
		return (FAILURE);
	return (ft_putchar('\n'));
}
