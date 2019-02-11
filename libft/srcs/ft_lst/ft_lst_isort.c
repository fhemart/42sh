/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_isort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 05:03:24 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 13:09:17 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_isort(t_list **head, t_list *toadd, int (*cmp)(t_list*, t_list*))
{
	t_list	*curr;
	t_list	*prev;

	curr = *head;
	prev = NULL;
	while (curr && cmp(curr, toadd) < 0)
	{
		prev = curr;
		curr = curr->next;
	}
	toadd->next = curr;
	if (prev)
		prev->next = toadd;
	else
		*head = toadd;
}
