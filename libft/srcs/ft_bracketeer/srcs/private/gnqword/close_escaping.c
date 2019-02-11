/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_escaping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 03:45:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/28 20:49:04 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

char		*close_escaping(t_brdata *data, char *start)
{
	size_t	size;

	size = data->src - start;
	if (*data->src)
	{
		ft_stack_get_content(data->brstack);
		data->src++;
	}
	size = data->src - start;
	return (ft_strndup(start, size));
}
