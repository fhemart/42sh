/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:39:05 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/07 02:49:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "ft_prompt_private.h"

static void		do_hexpand(t_term *term, t_shdata *data, char **line, int ps)
{
	char	*oldline;

	oldline = *line;
	if (*line && get_histexpand(data, term->prompt, line) == SUCCESS)
	{
		if (oldline != *line)
		{
			ft_putstr(*line);
			if ((*line)[ft_strlen(*line) - 1] != '\n')
				ft_putchar('\n');
		}
		if (data->donotexec == TRUE)
			print_and_save_line(data, line, ps);
	}
}

int				get_inputline(t_term *term, t_shdata *data, char **line, int ps)
{
	int		ret;

	*line = NULL;
	if (((data->is_fork & IS_RDFILE || data->opts & SET_GNL)
		&& (ret = gnl_mode(term, data, line, ps)) <= 0)
	|| (!(data->is_fork & IS_RDFILE) && !(data->opts & SET_GNL)
		&& (ret = get_ttyline(term, data->controls, line, ps)) <= 0))
		ft_strdel(line);
	else if ((data->opts & SET_HISTEXP))
		do_hexpand(term, data, line, ps);
	return (ret);
}
