/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:22:17 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 08:35:47 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

t_prompt			*ft_prompt_init(void)
{
	t_prompt		*new_prompt;

	if (!(new_prompt = malloc(sizeof(t_prompt))))
		return (NULL);
	ft_bzero(new_prompt, sizeof(t_prompt));
	if (!(new_prompt->pool = ft_pool_new(POOL_SIZE, sizeof(t_cell)))
	|| !(new_prompt->line = ft_dlist_createroot()))
	{
		ft_prompt_close(new_prompt);
		return (NULL);
	}
	ft_stack_init(&new_prompt->brstack, 8);
	new_prompt->exit = 1;
	return (new_prompt);
}
