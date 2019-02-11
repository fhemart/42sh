/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zebu_look_curr_expr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:58:01 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 15:00:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

void		*ft_zebu_look_curr_expr(t_tkn_factory *factory)
{
	return ((void*)ft_stack_looktop(factory->expressions));
}
