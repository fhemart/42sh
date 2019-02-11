/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 00:20:25 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/25 00:22:51 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstprint(t_list *lst)
{
	if (!lst)
		return ;
	ft_lstprint_content(lst);
	ft_putchar('\n');
	if (lst->next)
		ft_lstprint(lst->next);
	return ;
}
