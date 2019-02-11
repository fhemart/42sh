/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_dup2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:59:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 01:12:52 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int		call_dup2(int fdnew, int fdold)
{
	int		d2ret;

	if (fdnew == -1)
	{
		if (fdold != -1)
			protected_close(fdold);
		return (SUCCESS);
	}
	d2ret = dup2(fdnew, fdold);
	protected_close(fdnew);
	if (d2ret == FAILURE)
		return (p_ebadf(SHELL_NAME ": ", ft_static_itoa(fdnew)));
	return (SUCCESS);
}
