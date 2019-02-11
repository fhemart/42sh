/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:36:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 16:37:34 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void		clean_input(void)
{
	t_iuser		*iuser;

	if (!(iuser = new_iuser(NULL, NULL)))
		return ;
	ft_queue_destroy(&iuser->op_expr);
	ft_pool_close(&iuser->int_pool);
	get_iuser_tlex(NULL, FT_STDEL);
	get_sh_brdata(NULL, FT_STDEL);
	get_iuser_grammar(FT_STDEL);
	get_hist_tlex(FT_STDEL);
}
