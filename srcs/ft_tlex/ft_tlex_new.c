/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlex_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/07 10:54:49 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_tlexicon		*ft_tlex_new(char *src, t_bool use_escape, \
							t_tkn_grammar *grammar)
{
	t_tlexicon	*new;

	if (!(new = (t_tlexicon*)ft_memalloc(sizeof(t_tlexicon))))
		return (NULL);
	if (!get_token_pool(FT_STSET)
	|| !(new->tokens = ft_queue_new(TLEXICON_STACK_HEIGHT)))
	{
		free(new);
		return (NULL);
	}
	new->src = src;
	new->grammar = grammar;
	new->use_escape = use_escape;
	return (new);
}
