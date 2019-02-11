/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:35:41 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 20:06:29 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static void	siginthandler(int sig)
{
	if (sig == SIGINT)
		signal(SIGINT, siginthandler);
}

static char	*get_shrc_name(t_shdata *data)
{
	char		*shrcpath;
	size_t		hlen;
	char		*home;

	if (!(home = sh_env_getvalue(data->env, "HOME")))
		shrcpath = ft_strjoin("./", SHELL_RC);
	else if ((shrcpath = ft_strnew(\
						(hlen = ft_strlen(home)) + 1 + ft_strlen(SHELL_RC))))
	{
		ft_strcpy(shrcpath, home);
		shrcpath[hlen] = '/';
		ft_strcpy(shrcpath + hlen + 1, SHELL_RC);
	}
	return (shrcpath);
}

static int	get_shrc_fd(t_shdata *data)
{
	char		*shrcname;
	int			fd;

	if (!(shrcname = get_shrc_name(data)))
		return (-1);
	fd = open(shrcname, O_RDONLY);
	ft_strdel(&shrcname);
	return (fd);
}

static void	load_shellrc(t_shdata *data)
{
	int			fd;
	t_iuser		*iuser;
	int			old_fval[2];

	if ((fd = get_shrc_fd(data)) != -1
	&& (iuser = new_iuser("> ", data)))
	{
		old_fval[0] = data->is_fork;
		old_fval[1] = data->opts;
		data->shell_fd = fd;
		data->is_fork = IS_RDFILE | PRINT_PS;
		data->opts |= SET_GNL;
		while (get_command(data) == 1 && data->last_retval < 128)
		{
			ft_exec_inputlist(&data->command, data);
			if (data->opts & SET_ERREXIT
				&& data->last_retval != EXIT_SUCCESS)
				break ;
		}
		data->is_fork = old_fval[0];
		data->opts = old_fval[1];
		close(fd);
	}
	data->opts |= SET_HISTORY;
}

int			main(int ac, char **av, char **env)
{
	static t_shdata	ftsh;
	int				ret;

	signal(SIGINT, siginthandler);
	signal(SIGTSTP, SIG_IGN);
	if (init_shell_data(&ftsh, ac, av, env) == FAILURE)
		return (EXIT_FAILURE);
	if (init_tc_data(&ftsh, env) == FAILURE)
	{
		shdata_destroy(&ftsh);
		return (EXIT_FAILURE);
	}
	load_shellrc(&ftsh);
	while ((ret = get_command(&ftsh)) == 1)
	{
		ft_exec_inputlist(&ftsh.command, &ftsh);
		if (ftsh.opts & SET_ERREXIT && ftsh.last_retval != EXIT_SUCCESS)
			break ;
	}
	if (ret == 0 && !ftsh.is_fork && !(ftsh.opts & SET_GNL))
		ft_putstr("exit\n");
	exit_shell(NULL, &ftsh, ftsh.last_retval);
	return (EXIT_SUCCESS);
}
