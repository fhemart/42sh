/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_opexpr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:51:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_iuser.h"

void			remove_opexpr(t_iuser *iuser)
{
	int		*type;

	if (!(type = ft_queue_getback(iuser->op_expr)))
		return ;
	ft_pool_giveback(iuser->int_pool, type);
}
