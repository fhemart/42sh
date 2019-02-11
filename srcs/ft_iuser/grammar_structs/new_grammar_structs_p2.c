/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_grammar_structs_p2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:24:23 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 14:16:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"

t_subshell		*new_subshell(t_queue *ilist)
{
	t_subshell	*new;

	if (!(new = (t_subshell*)ft_memalloc(sizeof(t_subshell))))
		return (NULL);
	new->type = SUBSHELL_CMD;
	new->ilist = ilist;
	return (new);
}

t_andor			*new_andor(t_command *pipeline, int type)
{
	t_andor	*new;

	if (!(new = (t_andor*)malloc(sizeof(t_andor))))
		return (NULL);
	new->pipeline = pipeline;
	new->type = type;
	new->retvalue = 0;
	return (new);
}

t_inputlist		*new_inputlist(t_queue *and_or, int septype)
{
	t_inputlist	*new;

	if (!(new = (t_inputlist*)malloc(sizeof(t_inputlist))))
		return (NULL);
	new->and_or = and_or;
	new->septype = septype;
	return (new);
}
