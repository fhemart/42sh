/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cookedcmd_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:56:08 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void					cookedcmd_del(t_cookedcmd **cmd)
{
	t_cookedcmd	*dummy;

	if (!(dummy = *cmd))
		return ;
	ft_arstrdel(&dummy->argv);
	reset_cookedio(&dummy->cookedio);
}
