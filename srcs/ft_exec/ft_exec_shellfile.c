/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_shellfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 00:52:55 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	exec_error(char *argv1)
{
	ft_putstr_fd(SHELL_NAME": ", 2);
	ft_putstr_fd(argv1, 2);
	ft_putstr_fd(": exec format error\n", 2);
	return (FAILURE);
}

static void	prepare_shdata(t_shdata *data)
{
	t_prompt	*prompt;

	del_inputlist(&data->command);
	prompt = data->term->prompt;
	ft_lstdel(&prompt->str_line, ft_memdel);
	prompt->sline_iter = 0;
}

void		ft_exec_shellfile(t_cookedcmd *cmd, t_shdata *shdata)
{
	struct stat		st_stat;
	int				fd;
	int				status;

	if (lstat(cmd->name, &st_stat) == -1 || st_stat.st_size == 0
	|| (fd = open(cmd->name, O_RDONLY)) == -1)
		return ((void)exec_error(cmd->argv[0]));
	shdata->shell_fd = fd;
	status = SUCCESS;
	cookedcmd_del(&cmd);
	shdata->is_fork |= IS_RDFILE;
	prepare_shdata(shdata);
	while (get_command(shdata) == 1 && shdata->last_retval < 128)
	{
		ft_exec_inputlist(&shdata->command, shdata);
		if (shdata->opts & SET_ERREXIT && shdata->last_retval != EXIT_SUCCESS)
			break ;
	}
	exit_shell(cmd, shdata, shdata->last_retval);
}
