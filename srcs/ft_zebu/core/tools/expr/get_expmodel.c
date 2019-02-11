/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expmodel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:55:21 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 14:59:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_tkn_expr		*get_expmodel(t_tkn_grammar *grammar, int expid)
{
	if (!id_isexpr(expid))
		return (NULL);
	return (grammar->expr + (expid & ~EXPR_OFFSET_VAL));
}
