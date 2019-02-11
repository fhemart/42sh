/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_last_compatibility.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/30 18:11:55 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

void			look_last_compatibility(t_token *last, t_tlexicon *tlex, \
										t_tkn_template *templates)
{
	int		lhcat;

	if (last->type >= ft_tlex_gword(tlex))
		last->type = TT_COMMON;
	else if ((lhcat = get_token_cat(last, templates)) == -1)
		return ;
	else if (lhcat == TT_OPERATOR_TWOSIDED)
	{
		if (tlex->feeder && ft_tlex_feed(tlex) != -1)
			ft_tlex_fill(tlex);
	}
}
