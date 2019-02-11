/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_nothing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 04:06:45 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:30:11 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int					ft_control_nothing(t_prompt *prompt, t_term *term)
{
	(void)term;
	(void)prompt;
	return (TRUE);
}
