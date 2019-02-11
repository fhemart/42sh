/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delim_msk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 22:18:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_chrmsk		*get_delim_msk(int index)
{
	const char			*delim_str[WEXP_DCOUNT] = {WEXP_DSTR};
	static t_chrmsk		delim_msk[WEXP_DCOUNT];
	static t_bool		isset = FALSE;

	if (isset == FALSE)
	{
		isset = -1;
		while (++isset < WEXP_DCOUNT)
			delim_msk[isset] = new_chrmsk((char*)delim_str[isset]);
		isset = TRUE;
	}
	if (index & ~0xff)
		return (delim_msk + ((index >> 8) + WEXP_SPMSKOFFSET));
	return (delim_msk + index);
}
