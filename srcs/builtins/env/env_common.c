/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_common.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 02:06:57 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

void			get_env_info(t_setenvsave *save, t_shdata *data)
{
	t_sh_env	*env;

	env = data->env;
	if ((save->path = sh_env_getvalue(env, "PATH")))
		save->path = ft_strdup(save->path);
	if ((save->cdpath = sh_env_getvalue(env, "CDPATH")))
		save->cdpath = ft_strdup(save->cdpath);
}

void			check_env_info_update(t_setenvsave *save, t_shdata *data)
{
	char		*tmp;
	t_sh_env	*env;

	env = data->env;
	tmp = sh_env_getvalue(env, "PATH");
	if (save->path != tmp)
	{
		ft_lstdel(&data->info.path, ft_memdel);
		data->info.path = lst_from_var(tmp);
		data->books = gsd_books(FT_STSET, data->info.path, data->builtins);
	}
	tmp = sh_env_getvalue(env, "CDPATH");
	if (save->cdpath != tmp)
	{
		ft_lstdel(&data->info.cdpath, ft_memdel);
		data->info.cdpath = lst_from_var(tmp);
	}
	ft_strdel(&save->path);
	ft_strdel(&save->cdpath);
	data->info.home = sh_env_getvalue(env, "HOME");
}

static t_list	*new_strlst(char *from, char *to)
{
	t_list		*ret;

	if (!(ret = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if ((ret->content = ft_strndup(from, to - from)))
		ret->content_size = (to - from) + 1;
	else
		ret->content_size = 0;
	return (ret);
}

static void		parse_things(t_list **tmp, char **thing, char *home)
{
	char	*dummy;
	char	*find;

	dummy = *thing;
	if (*dummy == '~' && (!dummy[1] || dummy[1] == ':' || dummy[1] == '/'))
	{
		ft_lstadd(tmp, ft_lstnew(home, ft_strlen(home) + 1));
		dummy++;
	}
	if ((find = ft_strchr(dummy, ':')))
	{
		ft_lstadd(tmp, new_strlst(dummy, ++find));
		dummy = find;
	}
	else
	{
		ft_lstadd(tmp, ft_lstnew(dummy, ft_strlen(dummy) + 1));
		dummy = NULL;
	}
	*thing = dummy;
}

void			parse_tilde(char **src, t_sh_env *env)
{
	char	*dummy;
	t_list	*tmp;
	char	*home;

	if (!(home = sh_env_getvalue(env, "HOME"))
	|| !(dummy = *src)
	|| !(dummy = ft_strchr(*src, '=')))
		return ;
	tmp = NULL;
	ft_lstadd(&tmp, new_strlst(*src, ++dummy));
	while (dummy)
		parse_things(&tmp, &dummy, home);
	if (!tmp)
		return ;
	dummy = ft_lst2str(tmp);
	ft_lstdel(&tmp, ft_memdel);
	if (dummy)
		*src = dummy;
}
