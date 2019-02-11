/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_ins_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 18:50:12 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void		hist_ins_entry(t_histentry **prev_entry, t_histentry *to_ins)
{
	t_histentry		*dummy;

	if (!to_ins)
		return ;
	if ((dummy = *prev_entry))
	{
		dummy->next = to_ins;
		to_ins->prev = dummy;
	}
	*prev_entry = to_ins;
}
