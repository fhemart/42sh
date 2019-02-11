/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 04:39:47 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 08:29:15 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void **))
{
	if (!*alst || !del)
		return ;
	del(&(*alst)->content);
	free(*alst);
	*alst = NULL;
}
