/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_expr_to_blacklist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 10:29:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 14:59:18 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

void			add_expr_to_blacklist(t_blacklist *blacklist, int expr)
{
	int		i;
	int		j;

	expr = (expr & ~EXPR_OFFSET_VAL);
	i = expr / 32;
	j = expr % 32;
	if (blacklist->mask[i] & (1 << j))
		return ;
	blacklist->mask[i] |= (1 << j);
}
