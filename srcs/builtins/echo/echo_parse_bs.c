/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_parse_bs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 17:08:11 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static int	bs_act_c(t_awstr *awstr, char **src, int *cut)
{
	(void)awstr;
	(void)src;
	*cut = 1;
	return (0);
}

static int	bs_act_0(t_awstr *awstr, char **src, int *cut)
{
	char	oct;

	(void)cut;
	oct = parse_bsoct(*src, src);
	ft_awstrset(awstr, oct, 1);
	return (0);
}

static int	bs_act_u2(t_awstr *awstr, char **src, int *cut)
{
	t_unicode	ucode;
	char		*hptr;

	(void)cut;
	hptr = *src + 1;
	if (ft_ishexdec(*hptr))
	{
		ucode = hex_to_unicode(src[0] + 1, src, 8);
		ft_awstrncat(awstr, (char*)&ucode.c, ucode.size);
	}
	else
	{
		ft_awstrncat(awstr, "\\U", 2);
		*src = hptr;
	}
	return (0);
}

static int	bs_act_u1(t_awstr *awstr, char **src, int *cut)
{
	t_unicode	ucode;
	char		*hptr;

	(void)cut;
	hptr = *src + 1;
	if (ft_ishexdec(*hptr))
	{
		ucode = hex_to_unicode(src[0] + 1, src, 4);
		ft_awstrncat(awstr, (char*)&ucode.c, ucode.size);
	}
	else
	{
		ft_awstrncat(awstr, "\\2", 2);
		*src = hptr;
	}
	return (0);
}

char		*parse_bs(char *last, char *curr, t_awstr *awstr, int *cut)
{
	const char	seq[] = "\a\b\e\e\f\n\r\t\v\\";
	static int	(*act[5])(t_awstr*, char**, int*) = {bs_act_c, bs_act_0, \
											bs_act_hex, bs_act_u1, bs_act_u2};
	int			i;

	ft_awstrncat(awstr, last, curr - last);
	last = curr + 1;
	if ((i = is_escape_sequence(*last)) == -1)
		ft_awstrset(awstr, '\\', 1);
	else
	{
		if (i < (int)(sizeof(seq) - 1))
		{
			ft_awstrset(awstr, seq[i], 1);
			last++;
		}
		else
			act[i - (int)(sizeof(seq) - 1)](awstr, &last, cut);
	}
	return (last);
}
