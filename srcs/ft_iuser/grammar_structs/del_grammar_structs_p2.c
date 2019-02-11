/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_grammar_structs_p2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:25:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 14:15:35 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "token_charsets/input_grammar_struct.h"

void			del_andorstruct(t_andor **andor)
{
	t_andor *dummy;

	if (!(dummy = *andor))
		return ;
	del_pipeline(&dummy->pipeline);
	free(dummy);
	*andor = NULL;
}

void			del_andor_queue(void *andor)
{
	del_andorstruct((t_andor**)&andor);
}

void			del_andor(t_queue **andor)
{
	ft_queue_clean_destroy(andor, del_andor_queue);
}
