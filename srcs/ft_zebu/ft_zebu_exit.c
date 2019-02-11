/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zebu_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:47:24 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/05 12:01:49 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

void		ft_zebu_exit(void)
{
	get_token_stack(FT_STDEL);
	get_expr_stack(FT_STDEL);
	get_exptoken_pool(FT_STDEL);
	get_token_pool(FT_STDEL);
}
