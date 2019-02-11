/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hist_tlex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:08:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_tlexicon		*get_hist_tlex(int gsd)
{
	static t_tlexicon	*tlex = NULL;
	char				**brinf;

	if (gsd == FT_STGET)
	{
		if (!tlex
		&& (tlex = ft_tlex_new(NULL, TRUE, get_iuser_grammar(FT_STGET))))
		{
			brinf = get_sh_brinf();
			tlex->quote_data = create_new_brdata(brinf, SH_BRINFO_COUNT, TRUE);
		}
	}
	else if (gsd == FT_STDEL && tlex)
	{
		brdata_del(&tlex->quote_data);
		ft_tlex_destroy(&tlex);
	}
	return (tlex);
}
