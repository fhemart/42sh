/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_cmd_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/18 11:39:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

void	*reduce_cmd_word(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_exptoken	*cmd_prefix;
	t_command	*cmd;
	t_token		*word;
	char		*name;

	(void)expr;
	word = ft_zebu_get_curr_tok(tfactory);
	cmd_prefix = ft_zebu_look_curr_tok(tfactory);
	cmd = cmd_prefix->reduced;
	if (!(name = ft_memdup(word->content, word->content_size + 1)))
		ft_zebu_set_error(tfactory);
	else
		ft_queue_add(cmd->argv, name);
	token_del(&word);
	return (cmd);
}
