/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_histcontrol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 18:49:35 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			get_histcontrol(t_shdata *data)
{
	int		ret;
	char	*histcontrol;
	char	*colon;
	size_t	n;

	ret = 0;
	histcontrol = sh_env_getvalue(data->env, "HISTCONTROL");
	while (histcontrol)
	{
		if ((colon = ft_strchr(histcontrol, ':')))
			n = colon++ - histcontrol;
		else
			n = ft_strlen(histcontrol);
		if (ft_strnequ(histcontrol, "ignoredups", n))
			ret |= HC_IGNDUPS;
		else if (ft_strnequ(histcontrol, "ignorespace", n))
			ret |= HC_IGNSPACE;
		else if (ft_strnequ(histcontrol, "ignoreboth", n))
			ret |= HC_IGNBOTH;
		histcontrol = colon;
	}
	return (ret);
}
