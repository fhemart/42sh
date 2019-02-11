/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_cmd_prefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/09 18:44:25 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

static t_command	*get_cmd(t_tkn_factory *factory, t_exptoken *next_expr)
{
	t_command	*command;
	t_exptoken	*prev_prefix;

	if (!(prev_prefix = ft_zebu_look_curr_tok(factory))
	|| prev_prefix->id != E_CMD_PREFIX)
	{
		if (!(command = new_command()))
			return (NULL);
	}
	else
	{
		command = prev_prefix->reduced;
		ft_zebu_get_curr_tok(factory);
		token_del((t_token**)&prev_prefix);
	}
	ft_lstadd((t_list**)&command->iocontent, (t_list*)next_expr->reduced);
	return (command);
}

void				*reduce_cmd_prefix(t_tkn_factory *factory, t_exptoken *expr)
{
	t_command	*command;
	t_exptoken	*next_expr;

	(void)expr;
	next_expr = ft_zebu_get_curr_tok(factory);
	if (!(command = get_cmd(factory, next_expr)))
		factory->main_status = TF_STATUS_ERROR;
	token_del((t_token**)&next_expr);
	return (command);
}
