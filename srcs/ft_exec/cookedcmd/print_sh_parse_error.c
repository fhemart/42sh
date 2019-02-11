/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sh_parse_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 21:52:06 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void		print_sh_parse_error(t_shdata *data, char *errhead)
{
	char	*msg;

	msg = (char*)ft_zebu_get_errmsg();
	if (*msg)
	{
		if (errhead)
			ft_putstr_fd(errhead, 2);
		ft_putstr_fd(msg, 2);
	}
	data->command = NULL;
	data->last_retval = 2;
}
