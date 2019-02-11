/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlex_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/30 15:45:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

void		ft_tlex_fill(t_tlexicon *tlex)
{
	t_token			*curr_tok;
	t_wordpolish	*wpolish;
	t_queue			*tokqueue;

	wpolish = tlex->wpolish;
	tokqueue = tlex->tokens;
	while ((curr_tok = get_next_token(tlex)))
	{
		ft_queue_add(tokqueue, curr_tok);
		if (use_word_polish(tlex, curr_tok, wpolish) == -1)
		{
			ft_tlex_errtok(tlex);
			break ;
		}
	}
}
