/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfromarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 01:33:51 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 08:34:22 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstfromarray(char **ar)
{
	t_list	*head;
	t_list	*new;
	int		i;

	head = NULL;
	i = 0;
	while (ar[i])
	{
		if (!(new = ft_lstnew(ar[i], ft_strlen(ar[i]) + 1)))
			return (NULL);
		ft_lstadd(&head, new);
		i++;
	}
	return (head);
}
