/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlex_feed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:19:06 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/06 19:05:32 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

int				ft_tlex_feed(t_tlexicon *tlex)
{
	t_tlexfeed	*feeder;
	char		*newsrc;

	feeder = tlex->feeder;
	if (!(newsrc = feeder->error_lift(tlex, feeder->param)))
	{
		if (tlex->errhead)
			ft_putstr_fd(tlex->errhead, 2);
		ft_putstr_fd("syntax error: unexpected end of file\n", 2);
		tlex->main_status = TF_STATUS_ERROR;
		return (-1);
	}
	tlex->src = newsrc;
	return (0);
}
