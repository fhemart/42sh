/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 00:47:51 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 13:51:29 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_token	*create_new_token(const char *content, int size, int type)
{
	t_token		*new;

	if (!(new = ft_pool_get(get_token_pool(FT_STGET))))
		return (NULL);
	new->content = (char*)content;
	new->content_size = size;
	new->type = type;
	return (new);
}
