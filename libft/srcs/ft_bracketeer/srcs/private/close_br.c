/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_br.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:55:08 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/28 20:48:33 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

void		debug_closebr(t_brinfo *info)
{
	ft_putstr("[close_br] : (");
	ft_putnbr(info->size[BRACK_CLOSE]);
	ft_putstr(") '");
	ft_putstr(info->cl);
	ft_putstr("'\n");
}

void		close_br(t_brdata *data)
{
	t_brinfo	*info;

	info = (t_brinfo*)ft_stack_get_content(data->brstack);
	if (BRACK_DEBUGPRINT)
		debug_closebr(info);
	data->src += info->size[BRACK_CLOSE];
}
