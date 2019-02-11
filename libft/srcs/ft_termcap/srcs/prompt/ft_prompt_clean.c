/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:55:32 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/04 01:03:06 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int			ft_prompt_clean(t_term *term)
{
	if (term->mode == MODE_TRUNC)
		ft_prompt_cleanscreentr(term);
	else
		ft_prompt_cleanscren(term);
	return (SUCCESS);
}
