/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdata_addfeeder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 03:58:47 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/28 14:44:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

int			brdata_addfeeder(char *(*error_lift)(t_br_return*, void*), \
								void *param, t_brdata *data)
{
	t_brfeed	*feeder;

	if (!(feeder = (t_brfeed*)ft_memalloc(sizeof(t_brfeed))))
		return (-1);
	feeder->error_lift = error_lift;
	feeder->param = param;
	data->feeder = feeder;
	return (0);
}

int			brdata_updatefeeder(char *(*error_lift)(t_br_return*, void*), \
								void *param, t_brdata *data)
{
	t_brfeed	*feeder;

	if (!(feeder = data->feeder))
		return (brdata_addfeeder(error_lift, param, data));
	feeder->error_lift = error_lift;
	feeder->param = param;
	data->feeder = feeder;
	return (0);
}
