/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys_getenvinfo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:45:30 by fhemart           #+#    #+#             */
/*   Updated: 2018/08/25 20:17:13 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char							*ft_sys_getenvinfo(char **env, char *key)
{
	int							i;
	int							keylen;
	char						*found;

	i = 0;
	keylen = 0;
	if (!env || !key)
		return (NULL);
	keylen = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(env[i], key, keylen) == 0)
		{
			if ((found = ft_strchr(env[i], '=')))
				found++;
			return (found);
		}
		i++;
	}
	return (NULL);
}
