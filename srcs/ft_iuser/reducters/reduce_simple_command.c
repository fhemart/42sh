/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_simple_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/05 19:01:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

#include "ft_exec.h"

void		*reduce_simple_command(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_exptoken	*last_expr;
	t_command	*cmd;

	(void)expr;
	last_expr = ft_zebu_look_curr_tok(tfactory);
	cmd = last_expr->reduced;
	cmd->type = SIMPLE_CMD;
	clean_expr_overage(tfactory, expr);
	return (cmd);
}
