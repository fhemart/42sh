/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_tostring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 00:47:51 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 14:58:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

char	*tkn_tostring(t_tkn_grammar *grammar, int value)
{
	if (value < -1)
		return ("ERROR");
	if (value == -1)
		return ("END OF STATE");
	if (id_isexpr(value))
		return (grammar->expr[(value & ~EXPR_OFFSET_VAL)].tostring);
	return (grammar->token_str[value]);
}
