/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 00:22:05 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/25 00:22:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstprint(t_list *lst)
{
	if (!lst)
		return ;
	if (lst->next)
		ft_lstprint(lst->next);
	ft_lstprint_content(lst);
	ft_putchar('\n');
	return ;
}
