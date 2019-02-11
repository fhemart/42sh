/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 03:45:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 18:54:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

static void	merge_br_returns(t_br_return *br1, t_br_return *br2)
{
	char	*tmp;

	br1->status = br2->status;
	if (!(tmp = ft_strjoin(br1->parsed_src, br2->parsed_src)))
		br1->status = BR_ABORTED;
	ft_strdel(&br1->parsed_src);
	ft_strdel(&br2->parsed_src);
	br1->parsed_size += br2->parsed_size;
	free(br2);
	br1->parsed_src = tmp;
}

t_br_return	*try_extend(t_brdata *data, t_br_return *br_ret)
{
	t_br_return	*extend;
	t_brfeed	*feeder;

	if (!(feeder = data->feeder)
	|| !(data->src = feeder->error_lift(br_ret, feeder->param))
	|| !(extend = get_next_qword(data)))
	{
		br_ret->status = BR_ABORTED;
		return (br_ret);
	}
	merge_br_returns(br_ret, extend);
	close_br_return(br_ret);
	return (br_ret);
}
