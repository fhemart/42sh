/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_writetc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 17:59:31 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/14 18:16:16 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int			ft_term_writetc(char *cap)
{
	char	*tc;

	if ((tc = tgetstr(cap, NULL)))
	{
		ft_putstr(tc);
		return (SUCCESS);
	}
	return (FAILURE);
}
