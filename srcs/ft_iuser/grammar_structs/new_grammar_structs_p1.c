/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_grammar_structs_p1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:24:23 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 14:16:14 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"

t_iocontent		*new_iocontent(char *str, int type)
{
	t_iocontent	*new;

	if (!(new = (t_iocontent*)malloc(sizeof(t_iocontent))))
		return (NULL);
	new->str = str;
	new->type = type;
	return (new);
}

t_ioredirect	*new_ioredirect(t_iocontent *iocontent, int ionumber)
{
	t_ioredirect	*new;

	if (!(new = (t_ioredirect*)malloc(sizeof(t_ioredirect))))
		return (NULL);
	new->next = NULL;
	new->iocontent = iocontent;
	new->ionumber = ionumber;
	return (new);
}

t_command		*new_command(void)
{
	t_command	*new;

	if (!(new = (t_command*)ft_memalloc(sizeof(t_command))))
		return (NULL);
	if (!(new->argv = ft_queue_new(2)))
		del_command(&new);
	return (new);
}
