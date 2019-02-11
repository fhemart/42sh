/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:22:25 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/03 20:10:53 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"
#include "ft_lstrprivate.h"

void	ft_lstrdel(t_lstr **str)
{
	t_lstr		*tmp;

	if (!str)
		return ;
	while (*str)
	{
		tmp = (*str)->next;
		free(*str);
		*str = tmp;
	}
	*str = NULL;
}
