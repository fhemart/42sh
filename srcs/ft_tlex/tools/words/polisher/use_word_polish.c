/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_word_polish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/07 10:45:08 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

int			use_word_polish(t_tlexicon *tlex, t_token *tok, t_wordpolish *wpol)
{
	if (!wpol || tok->type != ft_tlex_gword(tlex))
		return (0);
	return (wpol->action(tlex, tok, wpol->param));
}
