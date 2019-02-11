/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:51:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/28 20:50:34 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

t_bool		check_brackets(t_brdata *data)
{
	t_chrmsk	*occ;

	occ = brdata_get_firstmsk(data);
	if (data->src)
	{
		while (*data->src)
		{
			if (char_match_pattern(*data->src, occ))
			{
				if (!(occ = update_info(data)))
					return (FALSE);
				if (current_is_validescape(data))
					occ = skip_escape(data);
			}
			else
				data->src++;
		}
	}
	if (ft_stack_isempty(data->brstack))
		return (TRUE);
	return (FALSE);
}
