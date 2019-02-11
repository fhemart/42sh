/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varkey_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 14:13:18 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

int			varkey_print(t_varkey *vk)
{
	if (ft_putstr(vk->key) == FAILURE
	|| ft_putstr("='") == FAILURE
	|| ft_putstr(vk->value) == FAILURE
	|| ft_putstr("'\n") == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
