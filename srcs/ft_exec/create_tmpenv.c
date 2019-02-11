/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmpenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 22:43:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

char		**create_tmpenv(t_cookedcmd *cmd)
{
	t_sh_evar	*cmdname;
	t_bool		delkey;
	char		*oldvalue;
	char		**ret;

	if (!(cmdname = sh_evar_getkey(cmd->env_var, "_", 1)))
	{
		cmdname = sh_evar_new("_", cmd->name);
		cmdname->isexport = TRUE;
		sh_evar_addkey(&cmd->env_var, cmdname);
		delkey = TRUE;
	}
	else
	{
		oldvalue = cmdname->value;
		cmdname->value = cmd->name;
		delkey = FALSE;
	}
	ret = sh_evar_toarraystring(cmd->env_var);
	if (delkey)
		sh_evar_delvar(&cmd->env_var, cmdname);
	else
		cmdname->value = oldvalue;
	return (ret);
}
