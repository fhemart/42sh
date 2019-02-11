/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_addnode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:10:57 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 02:52:39 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

int				ft_dlist_addnode(t_line *root, char c, t_pool *pool)
{
	if (!root || (c != '\t' && c != '\n' && ft_isprint(c) == FALSE))
		return (FAILURE);
	if (!root->current)
		ft_dlist_addfirstnode(root, c, pool);
	else if (root->current == root->head && root->cursor == *root->promptlen)
		ft_dlist_addfirstnode(root, c, pool);
	else if (root->current == root->last)
		ft_dlist_addlastnode(root, c, pool);
	else
		ft_dlist_addafternode(root, c, pool);
	root->nbelem++;
	return (SUCCESS);
}
