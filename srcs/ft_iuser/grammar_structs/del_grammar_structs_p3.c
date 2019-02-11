/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_grammar_structs_p3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:25:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 14:15:48 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "token_charsets/input_grammar_struct.h"

void		del_inputliststruct(t_inputlist **inputlist)
{
	t_inputlist *dummy;

	if (!(dummy = *inputlist))
		return ;
	del_andor(&dummy->and_or);
	free(dummy);
	*inputlist = NULL;
}

void		del_inputlist_queue(void *inputlist)
{
	del_inputliststruct((t_inputlist**)&inputlist);
}

void		del_inputlist(t_queue **inputlist)
{
	ft_queue_clean_destroy(inputlist, del_inputlist_queue);
}

void		del_subshell(t_subshell **subshell)
{
	t_subshell	*dummy;

	dummy = *subshell;
	del_iocontent(&dummy->iocontent);
	del_inputlist(&dummy->ilist);
	free(dummy);
	*subshell = NULL;
}
