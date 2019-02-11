/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_pasteright.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:59:50 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 06:53:21 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

int				ft_control_pasteright(t_prompt *prompt, t_term *term)
{
	ft_dlist_str2dlist(prompt->cpystr, term);
	ft_prompt_clean(term);
	return (SUCCESS);
}
