/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ps1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 04:17:06 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/26 17:31:18 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				display_ps1(t_iuser *iuser, char *ps1)
{
	char		*line;
	int			gnlret;
	t_term		*term;
	t_prompt	*prompt;
	t_shdata	*shdata;

	shdata = iuser->shdata;
	term = shdata->term;
	prompt = term->prompt;
	ft_strcpy(prompt->prompt, ps1);
	prompt->cparam = iuser;
	line = NULL;
	while ((gnlret = get_inputline(term, shdata, &line, 1)) > 0
	&& (!line || !*line))
	{
		ft_strcpy(prompt->prompt, ps1);
		ft_strdel(&line);
	}
	iuser->src = line;
	return (gnlret);
}
