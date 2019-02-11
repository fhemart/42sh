/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:25:30 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 16:25:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del_nothing(void **nothing)
{
	(void)nothing;
}

static t_list	*split_error(char **split, t_list *ret)
{
	ft_arstrdel(&split);
	ft_lstdel(&ret, del_nothing);
	return (NULL);
}

t_list			*ft_strsplit_lst(char *str, char delim)
{
	t_list	*ret;
	t_list	*new;
	char	**split;
	int		i;

	if (!(split = ft_strsplit(str, delim)))
		return (NULL);
	i = -1;
	ret = NULL;
	while (split[++i])
	{
		if (!(new = (t_list*)ft_memalloc(sizeof(t_list))))
			return (split_error(split, ret));
		new->content = split[i];
		new->content_size = ft_strlen(new->content);
		new->next = ret;
		ret = new;
	}
	free(split);
	return (ret);
}
