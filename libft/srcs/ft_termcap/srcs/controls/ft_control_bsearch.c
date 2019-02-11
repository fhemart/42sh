/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_bsearch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:37:51 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/02 14:59:03 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ftsh.h"
#include "ft_prompt_private.h"

int				save_line(t_shhist *hist, t_prompt *prompt, t_term *term)
{
	t_line		*line;
	char		*str;

	line = prompt->line;
	if (!(str = ft_dlist_clr_dlist2str(line, term)))
		return (FAILURE);
	hist_update_curr_histline(hist, str, TRUE);
	return (SUCCESS);
}

int				enter_bsearch(t_prompt *prompt, t_term *term)
{
	t_shhist	*hist;

	hist = ((t_iuser*)prompt->cparam)->shdata->history;
	if (PROMPT_DEBUG)
		ft_term_debug_putfd("enter bsearch");
	prompt->inbsearch = 1;
	if (save_line(hist, prompt, term) == FAILURE)
		return (FAILURE);
	ft_strcpy(prompt->promptsave, prompt->prompt);
	ft_strcpy(prompt->prompt, "(reverse-i-search)`");
	prompt->promptlen = ft_strlen(prompt->prompt);
	ft_putstr(prompt->prompt);
	prompt->line->cursor = prompt->promptlen;
	if (!(hist->last_bsentry = hist->current_histline))
		return (SUCCESS);
	write_hist_res(hist_get_modified(hist->last_bsentry), term);
	return (SUCCESS);
}

void			ft_prompt_exit_bsearch(t_term *term, t_bool restore)
{
	t_prompt	*prompt;
	char		*str;

	prompt = term->prompt;
	prompt->inbsearch = 0;
	ft_strcpy(prompt->prompt, prompt->promptsave);
	prompt->promptlen = ft_strlen(prompt->prompt);
	prompt->line->cursor = prompt->promptlen;
	if (restore == FALSE)
		hist_validate_bsearch(prompt->cparam);
	ft_prompt_cleanline((void**)&prompt->line->head, prompt->pool, \
						prompt->line);
	prompt->line->current = NULL;
	prompt->line->nbelem = 0;
	if ((str = get_hist_currline_mod(prompt->cparam)))
	{
		prompt->line->current = NULL;
		ft_dlist_str2dlist(str, term);
	}
}

int				ft_control_bsearch(t_prompt *prompt, t_term *term)
{
	if (term->mode == MODE_TRUNC)
		return (SUCCESS);
	ft_prompt_clean(term);
	if (!prompt->inbsearch)
		enter_bsearch(prompt, term);
	else
		bsearch_next(prompt, term);
	return (SUCCESS);
}
