/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_next_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:52:10 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/06 12:45:25 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_token	*take_next_token(t_tkn_factory *factory)
{
	return (ft_queue_get(factory->lex->tokens));
}
