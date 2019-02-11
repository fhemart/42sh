/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_compound_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/30 15:10:16 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

void		*reduce_compound_command(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_exptoken	*last_expr;
	t_command	*cmd;

	last_expr = ft_zebu_look_curr_tok(tfactory);
	cmd = last_expr->reduced;
	clean_expr_overage(tfactory, expr);
	return (cmd);
}
