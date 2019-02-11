/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlst2str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 05:24:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 18:06:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nlst_strtsize(t_list *lst, size_t n)
{
	size_t	ret;

	ret = 0;
	while (lst && n--)
	{
		ret += lst->content_size;
		lst = lst->next;
	}
	return (ret);
}

static size_t	copy_nlst2str(char *str, t_list *lst, size_t n)
{
	size_t		write_pos;

	if (!lst || !n)
		return (0);
	write_pos = copy_nlst2str(str, lst->next, n - 1);
	ft_strcpy(str + write_pos, lst->content);
	return (write_pos + (lst->content_size - 1));
}

char			*ft_nlst2str(t_list *lst, size_t n)
{
	char	*ret;
	size_t	total_size;

	if ((total_size = get_nlst_strtsize(lst, n)) == 0
	|| !(ret = ft_memalloc(total_size + 1)))
		return (NULL);
	copy_nlst2str(ret, lst, n);
	ret[total_size] = '\0';
	return (ret);
}
