/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 14:48:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

void	*reduce_filename(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_token	*word;
	char	*filename;

	(void)expr;
	word = ft_zebu_get_curr_tok(tfactory);
	filename = ft_memdup(word->content, word->content_size + 1);
	token_del(&word);
	return (filename);
}
