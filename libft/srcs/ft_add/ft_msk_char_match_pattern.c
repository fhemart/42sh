/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msk_char_match_pattern.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:32:20 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 02:37:11 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_msk_char_match_pattern(char c, t_chrmsk *chrmsk)
{
	if (chrmsk->pattern[c / 32] & (1 << (c % 32)))
		return (TRUE);
	return (FALSE);
}
