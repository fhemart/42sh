/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zebu_get_curr_tok.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:58:01 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 15:01:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

void		*ft_zebu_get_curr_tok(t_tkn_factory *factory)
{
	return (ft_stack_get_content(factory->tokens));
}
