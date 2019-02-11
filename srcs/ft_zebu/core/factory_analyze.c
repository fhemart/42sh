/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_analyze.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:39:42 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 11:40:00 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

void		factory_analyze(t_tkn_factory *factory)
{
	if (check_state(factory) != TF_CONTINUE)
		return ;
	while (fill_container(factory) == TF_CONTINUE
		&& check_substate(factory) == TF_SHIFT)
		shift(factory);
}
