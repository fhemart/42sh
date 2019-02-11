/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:29:44 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:49:48 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void				ft_prompt_close(t_prompt *prompt)
{
	ft_pool_close(&prompt->pool);
	ft_dlist_destroyroot(prompt->line);
	ft_memdel((void**)&prompt->cpystr);
	ft_memdel((void**)&prompt->beforetab);
	ft_stack_destroy(&prompt->brstack);
	ft_memdel((void**)&prompt);
}
