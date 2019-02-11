/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:25:15 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/26 17:30:06 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static char	*parse_home(char *ps1, char *home)
{
	int			i;

	if (!home)
		return (ps1);
	i = 0;
	while (ps1[i] == home[i] && ps1[i])
		i++;
	if (!home[i] && i != 0)
	{
		if (ps1[i] != '/')
		{
			if (i == 1)
				return (ps1);
			ps1[--i] = '/';
		}
		ps1[--i] = '~';
		return (ps1 + i);
	}
	return (ps1);
}

static char	*parse_ps1(t_shdata *data)
{
	static char		ps1[_POSIX_PATH_MAX];
	char			*env_pwd;

	if ((env_pwd = sh_env_getvalue(data->env, "PWD"))
	&& ft_strlen(env_pwd) < _POSIX_PATH_MAX - 3)
		ft_strcpy(ps1, env_pwd);
	else if (getcwd(ps1, _POSIX_PATH_MAX - 3) == NULL)
		*ps1 = '\0';
	ft_strcat(ps1, "$> ");
	return (parse_home(ps1, sh_env_getvalue(data->env, "HOME")));
}

int			get_command(t_shdata *shdata)
{
	t_iuser		*iuser;
	t_prompt	*prompt;
	int			inputret;

	prompt = shdata->term->prompt;
	if (!(iuser = new_iuser(parse_ps1(shdata), shdata)))
		return (-1);
	if ((inputret = iuser->start_input(iuser, iuser->ps1)) <= 0)
	{
		ft_lstdel(&prompt->str_line, ft_memdel);
		return (inputret);
	}
	parse_cmd(iuser, shdata, SHELL_NAME": ");
	add_cmd2history(shdata, prompt->str_line);
	ft_lstdel(&prompt->str_line, ft_memdel);
	ft_strdel(&iuser->src);
	return (1);
}
