/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_evar_tostring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/14 11:32:21 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

char		*sh_evar_tostring(t_sh_evar *model)
{
	size_t		klen;
	size_t		vlen;
	char		*ret;

	klen = ft_strlen(model->key);
	vlen = model->value ? ft_strlen(model->value) : 0;
	if (!(ret = ft_strnew(klen + 1 + vlen)))
		return (NULL);
	ft_strcpy(ret, model->key);
	ret[klen++] = '=';
	if (vlen)
		ft_strcpy(ret + klen, model->value);
	else
		ret[klen] = '\0';
	return (ret);
}
