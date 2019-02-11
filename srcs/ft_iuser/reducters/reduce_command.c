/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/07 10:28:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

void		*reduce_command(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_exptoken	*last_expr;
	t_iocontent	*rdlist;
	t_command	*cmd;

	last_expr = ft_zebu_get_curr_tok(tfactory);
	if (expr->validstate == 2)
	{
		rdlist = last_expr->reduced;
		token_del((t_token**)&last_expr);
		last_expr = ft_zebu_get_curr_tok(tfactory);
	}
	else
		rdlist = NULL;
	cmd = last_expr->reduced;
	if (rdlist)
		cmd->iocontent = rdlist;
	token_del((t_token**)&last_expr);
	return (cmd);
}
