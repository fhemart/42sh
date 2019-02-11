/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 00:47:51 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/06 19:06:31 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

static void	del_expr(t_token *tok)
{
	ft_pool_giveback(get_exptoken_pool(FT_STGET), tok);
}

static void	del_tok(t_token *tok)
{
	if (tok->content)
		free(tok->content);
	ft_pool_giveback(get_token_pool(FT_STGET), tok);
}

void		token_del(t_token **tok)
{
	t_token		*dummy;

	if (!(dummy = *tok))
		return ;
	id_isexpr(dummy->type) ? del_expr(dummy) : del_tok(dummy);
	*tok = NULL;
}
