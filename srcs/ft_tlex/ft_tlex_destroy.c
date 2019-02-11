/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlex_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/06 10:58:14 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

void			ft_tlex_destroy(t_tlexicon **tlex)
{
	t_token		*next_tok;

	if (!tlex || !*tlex)
		return ;
	while ((next_tok = (t_token*)ft_queue_get((*tlex)->tokens)))
		token_del(&next_tok);
	ft_queue_destroy(&(*tlex)->tokens);
	if ((*tlex)->feeder)
		free((*tlex)->feeder);
	if ((*tlex)->wpolish)
		free((*tlex)->wpolish);
	free(*tlex);
	*tlex = NULL;
}
