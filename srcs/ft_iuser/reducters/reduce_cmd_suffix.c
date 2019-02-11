/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_cmd_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/18 11:47:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

static int			add_param_to_cmd(t_command *cmd, t_token *word)
{
	char	*new_param;

	if (!(new_param = ft_memdup(word->content, word->content_size + 1)))
		return (FAILURE);
	else
		ft_queue_add(cmd->argv, new_param);
	return (SUCCESS);
}

static t_command	*update_cmd(t_tkn_factory *factory, t_exptoken *next_expr)
{
	t_command	*cmd;
	t_exptoken	*possible_recurse;

	possible_recurse = ft_zebu_look_curr_tok(factory);
	cmd = possible_recurse->reduced;
	if (next_expr->id == E_IO_REDIRECT)
		ft_lstadd((t_list**)&cmd->iocontent, (t_list*)next_expr->reduced);
	else if (add_param_to_cmd(cmd, (t_token*)next_expr) == FAILURE)
		del_command(&cmd);
	if (possible_recurse->id == E_CMD_SUFFIX)
	{
		ft_zebu_get_curr_tok(factory);
		token_del((t_token**)&possible_recurse);
	}
	return (cmd);
}

void				*reduce_cmd_suffix(t_tkn_factory *factory, t_exptoken *expr)
{
	t_command	*command;
	t_exptoken	*next_expr;

	(void)expr;
	next_expr = ft_zebu_get_curr_tok(factory);
	if (!(command = update_cmd(factory, next_expr)))
		ft_zebu_set_error(factory);
	token_del((t_token**)&next_expr);
	return (command);
}
