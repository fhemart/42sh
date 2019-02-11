/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varkey_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 13:29:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

void		varkey_del(t_varkey **vk)
{
	t_varkey	*dummy;

	if (!(dummy = *vk))
		return ;
	ft_strdel(&dummy->key);
	ft_strdel(&dummy->value);
	free(dummy);
	*vk = NULL;
}
