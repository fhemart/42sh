/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arstrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 03:43:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/01 22:35:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void					ft_arstrdel(char ***ar)
{
	int		i;
	char	**tab;

	if (!*ar)
		return ;
	tab = *ar;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	*ar = NULL;
}
