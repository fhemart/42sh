/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 04:56:23 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/10 23:11:49 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void **))
{
	t_list *next;

	while (*alst)
	{
		next = (*alst)->next;
		del(&((*alst)->content));
		free(*alst);
		*alst = next;
	}
}
