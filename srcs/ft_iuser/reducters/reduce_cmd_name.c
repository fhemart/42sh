/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_cmd_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/11 16:02:13 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

void	*reduce_cmd_name(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_command	*cmd;
	t_token		*word;
	char		*name;

	(void)expr;
	name = NULL;
	word = ft_zebu_get_curr_tok(tfactory);
	if ((cmd = new_command())
	&& (!(name = ft_memdup(word->content, word->content_size + 1))))
		ft_zebu_set_error(tfactory);
	else
		ft_queue_add(cmd->argv, name);
	token_del(&word);
	return (cmd);
}
