/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varkey_isort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 13:14:49 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

static int	key_cmp(t_varkey *vk1, t_varkey *vk2)
{
	return (ft_strcmp(vk1->key, vk2->key));
}

void		varkey_isort(t_varkey **head, t_varkey *toadd)
{
	t_list	**hdum;
	t_list	*tadum;

	hdum = (t_list**)head;
	tadum = (t_list*)toadd;
	return (ft_lst_isort(hdum, tadum, (int(*)(t_list*, t_list*))key_cmp));
}
