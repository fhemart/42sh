/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:22:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/02 15:55:45 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		add_arg_tolst(t_queue *argl, t_cmdarg *arg)
{
	char	*new;

	if (arg->size != -1)
	{
		if (!(new = ft_strdup(arg->buff))
		|| ft_queue_add(argl, new) == FAILURE)
			return (FAILURE);
	}
	arg->size = 0;
	return (SUCCESS);
}

int		copy_str2arg(t_cmdarg *arg, char *str, size_t n)
{
	size_t	argsize;

	argsize = arg->size;
	if (n + argsize > _POSIX_ARG_MAX + 1)
		return ((arg->status = FAILURE));
	ft_memcpy(arg->buff + argsize, str, n);
	argsize += n;
	arg->buff[argsize] = '\0';
	arg->size = argsize;
	return ((arg->status = SUCCESS));
}

int		copy_int2arg(t_cmdarg *arg, int i)
{
	char *str;

	str = ft_static_itoa(i);
	return (copy_str2arg(arg, str, ft_strlen(str)));
}

int		copy_chr2arg(t_cmdarg *arg, char c)
{
	size_t	argsize;
	char	*buff;

	argsize = arg->size;
	buff = arg->buff;
	if (argsize + 2 > _POSIX_ARG_MAX + 1)
		return ((arg->status = FAILURE));
	buff[argsize++] = c;
	buff[argsize] = '\0';
	arg->size = argsize;
	return ((arg->status = SUCCESS));
}

void	reset_arg(t_cmdarg *arg)
{
	arg->buff[0] = '\0';
	arg->size = 0;
	arg->status = SUCCESS;
}
