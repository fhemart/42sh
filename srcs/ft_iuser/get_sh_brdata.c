/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sh_brdata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:39:05 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:53:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

char		**get_sh_brinf(void)
{
	static char		*sh_brinf[3 * SH_BRINFO_COUNT] = {ALL_SHBRINF};

	return (sh_brinf);
}

t_brdata	*get_sh_brdata(t_iuser *iuser, int gsd)
{
	static t_brdata	*brdata;
	char			**brinf;

	if (gsd == FT_STGET)
	{
		if (!brdata)
		{
			brinf = get_sh_brinf();
			if (!(brdata = create_new_brdata(brinf, SH_BRINFO_COUNT, TRUE))
			|| brdata_addfeeder((char*(*)())br_display_ps2, \
										iuser, brdata) == -1)
				brdata_del(&brdata);
		}
	}
	else if (gsd == FT_STDEL)
		brdata_del(&brdata);
	return (brdata);
}
