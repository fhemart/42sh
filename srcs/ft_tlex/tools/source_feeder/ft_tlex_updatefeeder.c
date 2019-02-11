/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlexicon_addfeeder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 20:02:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/06 12:07:41 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

int			tlexicon_addfeeder(char *(*error_lift)(t_tlexicon*, void*), \
								void *param, t_tlexicon *tlex)
{
	t_tlexfeed	*feeder;

	if (!tlex || !(feeder = (t_tlexfeed*)ft_memalloc(sizeof(t_tlexfeed))))
		return (-1);
	feeder->error_lift = error_lift;
	feeder->param = param;
	tlex->feeder = feeder;
	return (0);
}

void		ft_tlex_updatefeeder(char *(*error_lift)(t_tlexicon*, void*), \
									void *param, t_tlexicon *tlex)
{
	t_tlexfeed	*feeder;

	if (!tlex || !(feeder = tlex->feeder))
		return ;
	feeder->error_lift = error_lift;
	feeder->param = param;
}
