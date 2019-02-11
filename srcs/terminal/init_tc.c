/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:53:58 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/04 18:01:49 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static t_term	*ft_term_ghost(void)
{
	t_term						*new_term;

	if (!(new_term = malloc(sizeof(t_term))))
		return (NULL);
	ft_bzero(new_term, sizeof(t_term));
	new_term->mode = 0;
	new_term->scrollcurs = -1;
	new_term->trunckmove = 0;
	return (new_term);
}

int				init_tc(t_term **term, char **env)
{
	char		*term_name;

	if (isatty(0) && isatty(1))
	{
		if ((term_name = ft_sys_getenvinfo(env, "TERM=")))
		{
			if (!(*term = ft_term_init(term_name)))
				return (FAILURE);
		}
		else
		{
			ft_putstr(DEF_TERMSELECT);
			if (!(*term = ft_term_init("xterm-256color")))
				return (FAILURE);
		}
	}
	else if (!(*term = ft_term_ghost()))
		return (FAILURE);
	if (!((*term)->prompt = ft_prompt_init()))
	{
		ft_term_close(*term);
		return (FAILURE);
	}
	return (SUCCESS);
}
