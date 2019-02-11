/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlex_addfeeder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:05:48 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/06 12:06:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

int			ft_tlex_addfeeder(char *(*error_lift)(t_tlexicon*, void*), \
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
