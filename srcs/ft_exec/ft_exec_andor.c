/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_andor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/12 22:38:25 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static int	ft_exec_default(t_command *pipeline, t_shdata *shdata, int prev_ret)
{
	(void)prev_ret;
	return (ft_exec_pipeline(pipeline, shdata));
}

static int	ft_exec_and(t_command *pipeline, t_shdata *shdata, int prev_ret)
{
	if (prev_ret == EXIT_SUCCESS)
		return (ft_exec_pipeline(pipeline, shdata));
	return (prev_ret);
}

static int	ft_exec_or(t_command *pipeline, t_shdata *shdata, int prev_ret)
{
	if (prev_ret != EXIT_SUCCESS)
		return (ft_exec_pipeline(pipeline, shdata));
	return (prev_ret);
}

int			ft_exec_andor(t_queue *aoqueue, t_shdata *shdata)
{
	static int	(*exec_f[3])(t_command*, t_shdata*, int) = {ft_exec_default, \
													ft_exec_and, ft_exec_or};
	t_andor		*andor;
	int			andor_ret;

	while ((andor = ft_queue_lookfront(aoqueue)))
	{
		andor_ret = exec_f[andor->type](andor->pipeline, shdata, andor_ret);
		del_andorstruct(&andor);
		ft_queue_get(aoqueue);
	}
	return (andor_ret);
}
