/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_rootquoting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 03:45:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/28 03:50:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

char		*find_next_quote(t_brdata *data, char *start)
{
	char	*dummy;
	size_t	size;

	if (!(dummy = chrmsk_getnext_match(data->src, &data->start_occ)))
		size = ft_strlen(start);
	else if (!is_openbr(data, dummy))
	{
		data->src = dummy + 1;
		return (find_next_quote(data, start));
	}
	else
		size = dummy - start;
	data->src = dummy;
	return (ft_strndup(start, size));
}
