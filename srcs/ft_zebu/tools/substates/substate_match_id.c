/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substate_match_id.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 21:34:36 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/05 10:41:11 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_bool			substate_match_id(t_exptoken *expr, int id)
{
	int		sstate;

	sstate = get_substate_value(expr);
	if (sstate == id)
		return (TRUE);
	return (FALSE);
}
