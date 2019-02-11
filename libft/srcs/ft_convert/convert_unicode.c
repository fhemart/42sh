/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:13:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 18:56:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		set_mask2(int uc)
{
	char convert[4];

	convert[0] = (UNIBYTE2 | ((char)(uc >> 6))) & (UNIBYTE2 | MASK2);
	convert[1] = (UNIBYTE1 | (char)(uc)) & (UNIBYTE1 | MASK1);
	*(short*)&convert[2] = 0;
	return (*(int*)convert);
}

static int		set_mask3(int uc)
{
	char convert[4];

	convert[0] = (UNIBYTE3 | ((char)(uc >> 12))) & (UNIBYTE3 | MASK3);
	convert[1] = (UNIBYTE1 | ((char)(uc >> 6))) & (UNIBYTE1 | MASK1);
	convert[2] = (UNIBYTE1 | (char)(uc)) & (UNIBYTE1 | MASK1);
	convert[3] = 0;
	return (*(int*)convert);
}

static int		set_mask4(int uc)
{
	char convert[4];

	convert[0] = (UNIBYTE4 | (char)(uc >> 18)) & (UNIBYTE4 | MASK4);
	convert[1] = (UNIBYTE1 | (char)(uc >> 12)) & (UNIBYTE1 | MASK1);
	convert[2] = (UNIBYTE1 | (char)(uc >> 6)) & (UNIBYTE1 | MASK1);
	convert[3] = (UNIBYTE1 | (char)(uc)) & (UNIBYTE1 | MASK1);
	return (*(int*)convert);
}

t_unicode		convert_unicode(int uc)
{
	static int	(*set_mask[3])(int) = {set_mask2, set_mask3, set_mask4};
	t_unicode	ucode;
	int			i;

	i = -1;
	while (uc >> (++i) && i < 32)
		;
	if (i <= 7)
		ucode.size = 1;
	else if (i <= 11)
		ucode.size = 2;
	else if (i <= 16)
		ucode.size = 3;
	else
		ucode.size = 4;
	if (ucode.size != 1)
		ucode.c = set_mask[ucode.size - 2](uc);
	else
		ucode.c = uc;
	return (ucode);
}
