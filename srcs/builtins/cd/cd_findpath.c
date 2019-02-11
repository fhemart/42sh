/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:15:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 16:43:56 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static void	cd_update_pwd(char *newpwd, t_shdata *shdata)
{
	char		tmp[_POSIX_PATH_MAX];
	t_sh_env	*env;
	char		*pwd;

	env = shdata->env;
	pwd = shdata->info.pwd;
	ft_strcpy(tmp, pwd);
	ft_strcpy(pwd, newpwd);
	sh_env_update2(env, "OLDPWD", tmp);
	sh_env_update2(env, "PWD", pwd);
}

static int	cd_go_dir(char *dir, t_shdata *shdata)
{
	if (*dir == '\0')
		return (SUCCESS);
	if (chdir(dir) == -1)
		return (FAILURE);
	cd_update_pwd(dir, shdata);
	return (SUCCESS);
}

static int	check_cdpath(int flags, char *pbuff, char *arg, t_list *cdpath)
{
	int		(*f)(char*, char*, char*);

	f = (flags & (1 << 1)) ? parse_file_physx : parse_file_lnk;
	if (is_dotdot(arg) || !cdpath)
		return (FAILURE);
	f(pbuff, arg, cdpath->content);
	parse_dots(pbuff, FALSE);
	if (is_directory(pbuff) == 0)
		return (SUCCESS);
	*pbuff = 0;
	return (check_cdpath(flags, pbuff, arg, cdpath->next));
}

int			access_folder(int flags, char *arg, char *pwd, t_shdata *shdata)
{
	char	path[_POSIX_PATH_MAX + 1];
	int		(*f)(char*, char*, char*);
	int		err_ret;

	*path = 0;
	f = (flags & (1 << 1)) ? parse_file_physx : parse_file_lnk;
	if ((err_ret = f(path, arg, pwd)) != 0)
		return (print_dir_error(arg, err_ret));
	parse_dots(path, FALSE);
	if ((err_ret = is_directory(path)) != 0)
		return (print_dir_error(arg, err_ret));
	return (cd_go_dir(path, shdata));
}

int			find_path(int flags, char *arg, t_shdata *shdata)
{
	char	path[_POSIX_PATH_MAX + 1];

	*path = 0;
	if (*arg != '/'
	&& check_cdpath(flags, path, arg, shdata->info.cdpath) == SUCCESS)
	{
		if (cd_go_dir(path, shdata) == FAILURE)
			return (EXIT_FAILURE);
		if (ft_putendl(path) == FAILURE)
			return (ft_write_error(SHELL_NAME": cd: "));
		return (EXIT_SUCCESS);
	}
	if (access_folder(flags, arg, shdata->info.pwd, shdata) != SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
