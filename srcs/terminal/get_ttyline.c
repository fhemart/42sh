/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ttyline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:54:41 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/07 02:49:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_prompt		*enter_prompt(t_prompt *prompt, int ps)
{
	if ((prompt->ps = ps) == 1)
	{
		ft_stack_reset(&prompt->brstack);
		prompt->exit = 1;
	}
	return (prompt);
}

void			update_prompt(t_prompt *prompt, t_shhist *hist)
{
	hist->current_histline = NULL;
	hist->last_bsentry = NULL;
	ft_putstr("\x1B[0m");
	prompt->promptlen = ft_strlen(prompt->prompt);
	prompt->line->promptlen = &prompt->promptlen;
	prompt->line->cursor = prompt->promptlen;
	ft_putstr(prompt->prompt);
}

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

static void		no_newline_case(void)
{
	ft_term_writetc(TC_REVERSEVID);
	ft_putstr("%\n");
	ft_term_writetc(TC_RESETVID);
}

int				get_ttyline(t_term *term, t_control *controls, char **line, \
							int ps)
{
	t_prompt	*prompt;
	t_shhist	*hist;

	prompt = enter_prompt(term->prompt, ps);
	hist = ((t_iuser*)prompt->cparam)->shdata->history;
	while (prompt->done == 0)
	{
		if (ft_term_get_curse_pos(term) > 1)
			no_newline_case();
		update_prompt(prompt, hist);
		ft_term_setcanon(term);
		ft_prompt_getline(prompt, term, controls);
		*line = ft_prompt_exportline(prompt->line, prompt);
		ft_prompt_cleanline((void**)&prompt->line->head, prompt->pool,\
								prompt->line);
		ft_bzero(prompt->line, (sizeof(t_line)));
		ft_term_restore(term);
		hist_suppress_modified(hist);
	}
	return (exit_prompt(prompt));
}
