/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:52:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/05 12:13:11 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_stack		*get_token_stack(int gsd)
{
	static t_stack	*tokens;

	if (gsd == FT_STGET)
	{
		if (!tokens)
		{
			if (!(tokens = ft_memalloc(sizeof(t_stack))))
				return (NULL);
			ft_stack_init(tokens, 10);
		}
		else
			ft_stack_reset(tokens);
	}
	else if (tokens && gsd == FT_STDEL)
	{
		ft_stack_destroy(tokens);
		free(tokens);
		tokens = NULL;
	}
	return (tokens);
}
