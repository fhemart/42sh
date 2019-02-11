/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_iuser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 04:17:06 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 22:58:59 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	init_iuser(t_iuser *iuser)
{
	if (!(iuser->grammar = get_iuser_grammar(FT_STGET))
	|| !(iuser->brdata = get_sh_brdata(iuser, FT_STGET))
	|| !(iuser->tlex = get_iuser_tlex(iuser, FT_STGET))
	|| !(iuser->op_expr = ft_queue_new(5))
	|| !(iuser->int_pool = ft_pool_new(5, sizeof(int))))
	{
		ft_queue_destroy(&iuser->op_expr);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_iuser		*new_iuser(char *ps1, t_shdata *shdata)
{
	static t_iuser		iuser;
	static t_bool		init = FALSE;

	if (init == FALSE)
	{
		get_iuser_expressions();
		if (init_iuser(&iuser) == FAILURE)
			return (NULL);
		iuser.tlex->quote_data = iuser.brdata;
		iuser.start_input = display_ps1;
		init = TRUE;
	}
	else
		get_iuser_tlex(&iuser, FT_STSET);
	iuser.ps1 = ps1;
	iuser.shdata = shdata;
	ft_pool_clear(iuser.int_pool);
	ft_queue_clear(iuser.op_expr);
	ft_strdel(&iuser.src);
	return (&iuser);
}
