/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_get_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:52:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/05 12:12:25 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

int			factory_get_stacks(t_tkn_factory *factory)
{
	int		ret;

	ret = 0;
	if (!(factory->tokens = get_token_stack(FT_STGET))
	|| (!(factory->expressions = get_expr_stack(FT_STGET))))
		ret = -1;
	if (ret == -1)
		ft_zebu_exit();
	return (ret);
}
