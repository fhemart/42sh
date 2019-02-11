/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend2qword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 02:06:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/07 15:08:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

void	create_last_tbroken(t_tlexicon *tlex, t_br_return *br_ret, t_lstr **str)
{
	char	*last_word;
	int		tword;
	t_token	*new_tok;

	if (br_ret->parsed_src)
		*str = ft__strcat(str, br_ret->parsed_src);
	if ((last_word = ft_lstr_tostring(*str)))
	{
		tword = ft_tlex_gword(tlex);
		new_tok = create_new_token(last_word, ft_lstrlen(*str), tword);
		ft_queue_add(tlex->tokens, new_tok);
	}
	ft_lstrdel(str);
}

int		extend2qword(t_tlexicon *tlex, t_lstr **str)
{
	t_br_return	*br_ret;

	brdata_resetsrc(tlex->quote_data, tlex->src);
	ft_memcpy(&tlex->quote_data->start_occ, tlex->grammar->quotingmsk, \
			sizeof(t_chrmsk));
	if (!(br_ret = get_next_qword(tlex->quote_data))
	|| br_ret->status != BR_SUCCESS)
	{
		create_last_tbroken(tlex, br_ret, str);
		cancel_qword_creation(tlex, br_ret);
		return (-1);
	}
	tlex->src = tlex->quote_data->src;
	*str = ft__strcat(str, br_ret->parsed_src);
	destroy_br_return(&br_ret, FALSE);
	return (0);
}
