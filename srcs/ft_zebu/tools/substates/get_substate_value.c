/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_substate_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 21:34:36 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/07 11:04:20 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

int				get_substate_value(t_exptoken *expr)
{
	return (expr->rules[(int)expr->state][(int)expr->substate]);
}
