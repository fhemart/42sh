/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_inputlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 18:02:03 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		ft_exec_inputlist(t_queue **cmdq, t_shdata *shdata)
{
	t_inputlist *ilist;
	t_queue		*dummy;

	if (!(dummy = *cmdq))
		return (shdata->last_retval);
	while ((ilist = ft_queue_lookfront(dummy)))
	{
		ft_exec_andor(ilist->and_or, shdata);
		del_inputliststruct(&ilist);
		ft_queue_get(dummy);
	}
	del_inputlist(cmdq);
	return (shdata->last_retval);
}
