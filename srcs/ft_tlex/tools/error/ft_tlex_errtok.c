/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlex_errtok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/06 11:58:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

void			ft_tlex_errtok(t_tlexicon *tlex)
{
	t_token		*curr_tok;

	if (tlex->errhead)
		ft_putstr_fd(tlex->errhead, 2);
	ft_putstr_fd("syntax error near unexpected token '", 2);
	if ((curr_tok = (t_token*)ft_queue_lookback(tlex->tokens)))
		ft_putstr_fd(tkn_tostring(tlex->grammar, curr_tok->type), 2);
	ft_putstr_fd("'\n", 2);
	tlex->main_status = TF_STATUS_ERROR;
}
