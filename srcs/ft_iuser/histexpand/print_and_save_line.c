/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_save_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:36:12 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				print_and_save_line(t_shdata *data, char **line, int ps)
{
	int			ret;
	t_prompt	*prompt;

	**line = '\0';
	prompt = data->term->prompt;
	ret = SUCCESS;
	if (ps == 1)
	{
		ret = add_cmd2history(data, prompt->str_line);
		ft_lstdel(&prompt->str_line, ft_memdel);
		prompt->sline_iter = 0;
	}
	else
		ret = SUCCESS;
	data->donotexec = FALSE;
	return (ret);
}
