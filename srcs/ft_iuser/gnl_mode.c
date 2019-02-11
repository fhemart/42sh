/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:39:05 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/04 19:03:22 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "ft_prompt_private.h"

static int		exit_prompt(t_prompt *prompt)
{
	prompt->done = 0;
	if (prompt->exit == 0 && prompt->ps != 4)
	{
		ft_lstdel(&prompt->str_line, ft_memdel);
		prompt->sline_iter = 0;
	}
	return (prompt->exit);
}

static void		exportline(char **line, t_prompt *prompt, t_term *term)
{
	ft_dlist_str2dlist(*line, term);
	prompt->line->current = prompt->line->last;
	ft_dlist_addnode(prompt->line, '\n', prompt->pool);
	ft_strdel(line);
	*line = ft_prompt_exportline(prompt->line, prompt);
}

void			print_prompt(t_shdata *data, t_prompt *ppt)
{
	if (ppt->done != 0)
		return ;
	if (isatty(2) && ppt && (data->is_fork & PRINT_PS)
	&& !(data->is_fork & IS_RDFILE))
	{
		if (ppt->promptlen > 0)
			ppt->prompt[ppt->promptlen - 1] = '\0';
		ft_putstr_fd(ppt->prompt, 2);
	}
}

int				prepare_prompt(t_shdata *data, t_shhist *hist, t_prompt *ppt)
{
	(void)data;
	hist->current_histline = NULL;
	hist->last_bsentry = NULL;
	ppt->line->promptlen = &ppt->promptlen;
	return (1);
}

int				gnl_mode(t_term *term, t_shdata *data, char **line, int ps)
{
	t_prompt	*ppt;
	int			fd;

	ppt = term->prompt;
	fd = data->is_fork & IS_RDFILE ? data->shell_fd : 0;
	if ((ppt->ps = ps) == 1)
	{
		ft_stack_reset(&ppt->brstack);
		ppt->exit = 1;
	}
	ppt->ps = ps;
	print_prompt(data, ppt);
	while (ppt->done == 0)
	{
		ppt->done = prepare_prompt(data, data->history, ppt);
		if ((ppt->exit = get_next_line(fd, line)) <= 0)
			break ;
		exportline(line, ppt, term);
		ft_prompt_cleanline((void**)&ppt->line->head, ppt->pool, ppt->line);
		ft_bzero(ppt->line, (sizeof(t_line)));
		hist_suppress_modified(data->history);
		print_prompt(data, ppt);
	}
	return (exit_prompt(ppt));
}
