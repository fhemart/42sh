/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlex_resetsrc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/06 10:54:01 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

void			ft_tlex_resetsrc(t_tlexicon *tlex, char *src)
{
	t_queue	*tqueue;
	t_token	*dum;

	tqueue = tlex->tokens;
	while ((dum = ft_queue_get(tqueue)))
		token_del(&dum);
	ft_queue_clear(tqueue);
	tlex->src = src;
}
