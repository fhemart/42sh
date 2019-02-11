/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 05:24:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 18:05:50 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_lst_strtsize(t_list *lst)
{
	size_t	ret;

	ret = 0;
	while (lst)
	{
		ret += lst->content_size;
		lst = lst->next;
	}
	return (ret);
}

static size_t	copy_lst2str(char *str, t_list *lst)
{
	size_t		write_pos;

	if (!lst)
		return (0);
	write_pos = copy_lst2str(str, lst->next);
	ft_strcpy(str + write_pos, lst->content);
	return (write_pos + (lst->content_size - 1));
}

char			*ft_lst2str(t_list *lst)
{
	char	*ret;
	size_t	total_size;

	if ((total_size = get_lst_strtsize(lst)) == 0
	|| !(ret = ft_memalloc(total_size + 1)))
		return (NULL);
	copy_lst2str(ret, lst);
	ret[total_size] = '\0';
	return (ret);
}
