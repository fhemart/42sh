/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_closure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 03:45:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/28 20:49:12 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

size_t		get_qword_size(t_brdata *data, t_chrmsk *occ, char *start)
{
	char	*dummy;
	size_t	size;

	while (!ft_stack_isempty(data->brstack)
	&& (dummy = chrmsk_getnext_match(data->src, occ)))
	{
		data->src = dummy;
		occ = update_info(data);
		if (current_is_validescape(data))
			occ = skip_escape(data);
	}
	size = (!dummy) ? ft_strlen(start) : (size_t)(data->src - start);
	if (!dummy)
		data->src = start + size;
	return (size);
}

char		*find_next_closure(t_brdata *data, t_chrmsk *occ, char *start)
{
	size_t	size;

	size = get_qword_size(data, occ, start);
	return (ft_strndup(start, size));
}
