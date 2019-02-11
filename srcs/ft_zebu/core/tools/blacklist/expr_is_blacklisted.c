/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_is_blacklisted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 10:29:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 14:59:35 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_bool			expr_is_blacklisted(t_blacklist *blacklist, int expr)
{
	expr = (expr & ~EXPR_OFFSET_VAL);
	if (blacklist->mask[expr / 32] & (1 << (expr % 32)))
		return (TRUE);
	return (FALSE);
}
