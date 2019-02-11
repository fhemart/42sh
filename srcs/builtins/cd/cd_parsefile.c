/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_parsefile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:20:57 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 16:23:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

int			parse_file_lnk(char *buff, char *arg, char *pwd)
{
	size_t		len;

	if (*arg != '/')
	{
		ft_memcpy(buff, pwd, (len = ft_strlen(pwd)));
		if (buff[len - 1] != '/')
			buff[len++] = '/';
		buff += len;
	}
	ft_memcpy(buff, arg, ft_strlen(arg) + 1);
	return (SUCCESS);
}

int			parse_file_physx(char *buff, char *arg, char *pwd)
{
	size_t		len;
	int			cpy_ret;

	len = 0;
	if (*arg != '/')
	{
		if (!pwd)
			return (-1);
		if ((cpy_ret = follow_links(buff, len, pwd)) < 0)
			return (cpy_ret);
		len = cpy_ret;
	}
	else
		*(short*)buff = *(short*)"/";
	if ((cpy_ret = follow_links(buff, len, arg)) < 0)
		return (cpy_ret);
	return (SUCCESS);
}
