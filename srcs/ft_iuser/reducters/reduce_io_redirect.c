/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/13 11:24:57 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

static int		get_ionumber(t_tkn_factory *factory, int iotype)
{
	t_token		*tok;
	int			io_number;

	if (!(tok = ft_zebu_look_curr_tok(factory))
	|| tok->type != TIONUMBER)
		return ((iotype & ~1) && iotype < HEREDOCOFFSET ? 1 : 0);
	io_number = tok->content_size;
	ft_zebu_get_curr_tok(factory);
	token_del(&tok);
	return (io_number);
}

void			*reduce_io_redirect(t_tkn_factory *factory, t_exptoken *expr)
{
	t_exptoken		*exp_iocontent;
	t_iocontent		*io_content;

	(void)expr;
	exp_iocontent = ft_zebu_get_curr_tok(factory);
	io_content = exp_iocontent->reduced;
	token_del((t_token**)&exp_iocontent);
	io_content->ionumber = get_ionumber(factory, io_content->type);
	return (io_content);
}
