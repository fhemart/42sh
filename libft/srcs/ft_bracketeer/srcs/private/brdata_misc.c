/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdata_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:54:39 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/28 20:48:09 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

static t_chrmsk	*find_correct_mask(t_brdata *data)
{
	t_brinfo	*sinfo;

	if ((sinfo = (t_brinfo*)ft_stack_looktop(data->brstack)))
	{
		if (sinfo->type == BR_ESCAPE && data->src && *data->src)
		{
			data->src++;
			ft_stack_get_content(data->brstack);
			if (!(sinfo = (t_brinfo*)ft_stack_looktop(data->brstack)))
				return (&data->start_occ);
		}
		return (&((t_brinfo*)ft_stack_looktop(data->brstack))->expmatch);
	}
	return (&data->start_occ);
}

t_chrmsk		*brdata_get_firstmsk(t_brdata *data)
{
	t_brset		*dummy;
	char		c[2];

	if (data->isset)
		return (find_correct_mask(data));
	c[1] = '\0';
	data->start_occ = new_chrmsk("");
	dummy = data->sets;
	while (dummy)
	{
		c[0] = *dummy->info.op;
		ft_chrmskadd(&data->start_occ, c);
		dummy = dummy->next;
	}
	data->isset = TRUE;
	return (&data->start_occ);
}
