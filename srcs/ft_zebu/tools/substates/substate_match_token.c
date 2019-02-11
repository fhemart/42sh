/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substate_match_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 21:34:36 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/05 10:41:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_bool			substate_match_token(t_exptoken *expr, t_token *tkn)
{
	return (substate_match_id(expr, tkn->type));
}
