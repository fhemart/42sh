/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_grammar_structs_p1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:25:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 14:14:51 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "token_charsets/input_grammar_struct.h"

void			delone_iocontent(t_iocontent **iocontent)
{
	t_iocontent *dummy;

	if (!(dummy = *iocontent))
		return ;
	ft_strdel(&dummy->str);
	free(dummy);
	*iocontent = NULL;
}

void			del_iocontent(t_iocontent **iocontent)
{
	t_iocontent *dummy;

	if (!(dummy = *iocontent))
		return ;
	del_iocontent(&dummy->next);
	delone_iocontent(iocontent);
}

void			del_argv(void *av)
{
	if (av)
		free(av);
}

void			del_command(t_command **command)
{
	t_command *dummy;

	if (!(dummy = *command))
		return ;
	if (dummy->type == SUBSHELL_CMD)
		return (del_subshell((t_subshell**)command));
	del_iocontent(&dummy->iocontent);
	ft_queue_clean_destroy(&dummy->argv, del_argv);
	free(dummy);
	*command = NULL;
}

void			del_pipeline(t_command **pipeline)
{
	t_command		*dummy;

	if (!(dummy = *pipeline))
		return ;
	del_pipeline(&dummy->next);
	del_command(pipeline);
}
