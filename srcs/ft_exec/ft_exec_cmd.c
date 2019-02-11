/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 13:49:26 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			ft_exec_cmd(t_command *cmd_raw, t_shdata *shdata)
{
	t_cookedcmd		*cmd;
	int				exec_ret;

	if (!(cmd = cookedcmd_new(cmd_raw, shdata)))
		return (shdata->last_retval);
	exec_ret = ft_exec_cookedcmd(cmd, shdata);
	cookedcmd_del(&cmd);
	return (exec_ret);
}
