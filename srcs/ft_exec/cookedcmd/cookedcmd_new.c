/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cookedcmd_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 02:58:34 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			get_cmdtype(t_cookedcmd *cmd, t_shdata *data, char *errhead)
{
	int		ret;

	if ((ret = get_builtin(data->builtins, cmd->argv[0])) != NOT_BUILTIN)
		return (ret);
	else if (!(cmd->name = get_command_name(cmd, data, errhead))
	|| (is_executable(cmd->name, TRUE, errhead, cmd->argv[0]) == FALSE))
		return (-1);
	return (FT_EXC_FILE);
}

void		init_stdiotable(int *stdio)
{
	stdio[0] = 0;
	stdio[1] = 1;
	stdio[2] = 2;
}

static int	create_argv(t_cookedcmd *cmd, t_command *raw)
{
	char	**argv;
	t_queue	*argq;
	char	*arg;
	int		i;

	if (!(argv = ft_arstrnew(cmd->argc)))
		return (FAILURE);
	argq = raw->argv;
	i = 0;
	while ((arg = ft_queue_get(argq)))
		argv[i++] = arg;
	cmd->argv = argv;
	return (SUCCESS);
}

t_cookedcmd	*cookedcmd_new(t_command *raw, t_shdata *data)
{
	static t_cookedcmd	cmd;

	ft_bzero(&cmd, sizeof(cmd));
	cmd.ioctt = raw->iocontent;
	cmd.env_var = data->env->var;
	if (fill_argv(&cmd, raw, data) == FAILURE
	|| create_argv(&cmd, raw) == FAILURE
	|| (cmd.type = get_cmdtype(&cmd, data, SHELL_NAME": ")) == -1)
	{
		ft_arstrdel(&cmd.argv);
		return (NULL);
	}
	init_stdiotable(cmd.cookedio.stdio);
	return (&cmd);
}
