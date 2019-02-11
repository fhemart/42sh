/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdata_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:44:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/28 20:55:23 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

void		bracket_addnewset(t_brdata *data, t_brset *set)
{
	ft_lstadd((t_list**)&data->sets, (t_list*)set);
}

t_bool		is_openbr(t_brdata *data, char *index)
{
	t_brset	*dummy;

	dummy = data->sets;
	while (dummy)
	{
		if (ft_strnequ(dummy->info.op, index, dummy->info.size[BRACK_OPEN]))
			return (TRUE);
		dummy = dummy->next;
	}
	return (FALSE);
}

t_bool		is_closedbr(t_brdata *data, char *index)
{
	t_brinfo	*info;

	if (!(info = (t_brinfo*)ft_stack_looktop(data->brstack))
	|| info->type == BR_ESCAPE
	|| !ft_strnequ(info->cl, index, info->size[BRACK_CLOSE]))
		return (FALSE);
	return (TRUE);
}

void		brdata_del(t_brdata **brdata)
{
	t_brdata	*tmp;
	t_brset		*set;

	if (!brdata || !(tmp = *brdata))
		return ;
	while ((set = tmp->sets))
	{
		tmp->sets = set->next;
		free(set);
	}
	ft_stack_destroy(tmp->brstack);
	free(tmp->brstack);
	if (tmp->feeder)
		free(tmp->feeder);
	free(tmp);
	*brdata = NULL;
}
