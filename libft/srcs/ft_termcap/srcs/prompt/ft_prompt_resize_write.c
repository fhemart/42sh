/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_resize_write.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 06:23:39 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 08:26:41 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

void			ft_prompt_resize_write(t_term *termptr, t_con *con)
{
	(void)con;
	ft_prompt_wrupdate(termptr->prompt, termptr);
	termptr->enterhit = 1;
	termptr->cc = 0;
}
