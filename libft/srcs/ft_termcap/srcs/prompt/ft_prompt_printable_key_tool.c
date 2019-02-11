/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_printable_key_tool.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 09:55:03 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 10:00:02 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"
#include "ftsh.h"

int							get_scrollcurs(int cursor, t_term *term, \
											t_prompt *prompt, t_con *con)
{
	int						nbelem;
	int						scrollcurs;
	int						promptlen;
	int						size;

	promptlen = prompt->promptlen;
	scrollcurs = term->scrollcurs;
	nbelem = prompt->line->nbelem;
	size = con->size;
	if (cursor < SECU_OFFSET + promptlen)
		return (0);
	else if (scrollcurs > nbelem - (size - 7))
	{
		if (term->trunckmove == -1 \
		&& scrollcurs + term->nbcharwrite != nbelem)
			scrollcurs += 1;
		return (scrollcurs);
	}
	else
		return (cursor - promptlen - 1 - prompt->hasauto ? 3 : 0);
}

int							write_ins_truncated(t_line *line, t_term *term)
{
	int						ret;
	int						scrollcurs;
	t_prompt				*prompt;

	prompt = term->prompt;
	scrollcurs = get_scrollcurs(line->cursor, term, prompt, term->con);
	ft_prompt_clean(term);
	ret = ft_prompt_wrat2(term, scrollcurs);
	term->scrollcurs = scrollcurs;
	return (ret);
}

void						printkey_in_tr(int scrollcurs, int hasauto, \
									t_term *term, t_prompt *prompt)
{
	t_line					*line;

	line = prompt->line;
	scrollcurs = line->cursor - term->prompt->promptlen;
	scrollcurs -= hasauto ? 3 : 0;
	ft_prompt_clean(term);
	term->mode = MODE_TRUNC;
	ft_term_writetc(TC_INTI);
	term->nbcharwrite = ft_prompt_wrat2(term, scrollcurs);
	term->scrollcurs = scrollcurs;
}
