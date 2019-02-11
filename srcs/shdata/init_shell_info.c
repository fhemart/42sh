/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:42:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/11 12:53:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_list		*lst_from_var(char *var)
{
	t_list	*path;
	char	*colon;
	size_t	plen;

	if (!var || !*var)
		return (NULL);
	colon = ft_strchr(var, ':');
	plen = colon ? (size_t)(colon - var) : ft_strlen(var);
	if (!plen)
		return (colon ? lst_from_var(colon + 1) : NULL);
	var[plen] = '\0';
	path = ft_lstnew(var, plen + 1);
	if (colon)
		var[plen] = ':';
	if (!path)
		return (NULL);
	path->next = colon ? lst_from_var(colon + 1) : NULL;
	return (path);
}

void		print_epwd(void)
{
	ft_putstr_fd(SHELL_NAME": fatal error: failed to initialize pwd.\n", 2);
}

char		*getpwd_str(t_sh_env *env)
{
	static char		pwd[_POSIX_PATH_MAX];
	char			*pwd_var;

	if ((pwd_var = sh_env_getvalue(env, "PWD"))
	&& ft_strlen(pwd_var) < _POSIX_PATH_MAX
	&& is_directory(pwd_var) == 0)
		ft_strcpy(pwd, pwd_var);
	else if (!getcwd(pwd, _POSIX_PATH_MAX - 1))
	{
		if (chdir("/") == -1)
		{
			print_epwd();
			return (NULL);
		}
		*(short*)pwd = *(short*)"/";
	}
	return (pwd);
}

int			init_shell_info(t_shdata *shdata)
{
	t_shinfo	*info;
	t_sh_env	*env;

	info = &shdata->info;
	env = shdata->env;
	info->path = lst_from_var(sh_env_getvalue(env, "PATH"));
	info->cdpath = lst_from_var(sh_env_getvalue(env, "CDPATH"));
	if ((info->pwd = getpwd_str(env)) == NULL)
		return (FAILURE);
	info->home = sh_env_getvalue(env, "HOME");
	return (SUCCESS);
}
