/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 21:49:27 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

char		parse_bsoct(char *bs, char **src)
{
	char	oct;
	int		len;

	++bs;
	len = 0;
	oct = 0;
	while (len < 3 && ft_isoctal(bs[len]))
		oct = oct * 8 + (bs[len++] - '0');
	*src = bs + len;
	return (oct);
}

char		parse_bshex(char *bs, char **src)
{
	char	hex;
	int		hdc;
	int		len;

	len = 1;
	hex = ft_hdtoi(*bs);
	if ((hdc = ft_hdtoi(bs[1])) != -1)
	{
		hex = hex * 16 + hdc;
		len++;
	}
	*src = bs + len;
	return (hex);
}

char		parse_bsctrl(char *bs, char **src)
{
	char	bs2;

	bs2 = bs[2] % 32;
	*src = bs + 3;
	return (bs2);
}

char		parse_backslash_total(char *bs, char **src)
{
	t_chrmsk	*bsmsk;
	char		bs1;
	int			tr_i;

	bsmsk = get_delim_msk(WEXP_BSMSK);
	bs1 = bs[1];
	if (ft_isoctal(bs1))
		return (parse_bsoct(bs, src));
	else if (bs1 == 'c')
		return (parse_bsctrl(bs, src));
	else if (bs1 == 'x' && ft_ishexdec(bs[2]))
		return (parse_bshex(bs + 2, src));
	else if (char_match_pattern(bs1, bsmsk)
	&& (tr_i = ft_chr2index(WEXP_BSSTRM, bs1)) != -1)
	{
		*src = bs + 2;
		return (WEXP_BSEQM[tr_i]);
	}
	*src = bs + 1;
	return ('\\');
}
