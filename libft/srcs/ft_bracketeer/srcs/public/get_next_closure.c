/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_closure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 03:45:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/28 20:50:40 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

char	*get_next_closure(t_brdata *data, char *opened_quote)
{
	char			*start;
	t_chrmsk		*occ;
	t_brinfo		*info;
	size_t			size;

	data->src = opened_quote;
	if (!(start = data->src) || !*start)
		return (NULL);
	occ = check_firstchar(data);
	size = 0;
	if (!(info = (t_brinfo*)ft_stack_looktop(data->brstack)))
		return (NULL);
	else if (info->type == BR_QUOTE)
		size = get_qword_size(data, occ, start);
	else if (info->type == BR_ESCAPE)
		size = (opened_quote[1] ? 2 : 1);
	return (opened_quote + size);
}
