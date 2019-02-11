/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_container.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:52:10 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/06 19:07:36 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

int				fill_container(t_tkn_factory *factory)
{
	size_t		expr_size;

	expr_size = ft_stack_totalsize(factory->expressions);
	if (!factory->tokencontainer)
	{
		if (!(factory->tokencontainer = take_next_token(factory)))
		{
			factory->main_status = TF_STATUS_CLOSING;
			return (TF_LEXEND);
		}
	}
	if (expr_size == 0)
		return (ft_zebu_set_error(factory));
	return (TF_CONTINUE);
}
