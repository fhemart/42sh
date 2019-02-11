/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 22:57:58 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/07 11:48:27 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*dup_it(t_list **target, t_list *dup)
{
	if (dup->next)
		ft_lstadd(target, dup_it(target, dup->next));
	return (ft_lstnew(dup->content, dup->content_size));
}

t_list				*ft_lstdup(t_list *dup)
{
	t_list	*ret;

	if (!dup)
		return (NULL);
	ret = NULL;
	ft_lstadd(&ret, dup_it(&ret, dup));
	return (ret);
}
