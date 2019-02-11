/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_bsearch_tools.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 09:49:11 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 09:58:24 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"
#include "ftsh.h"

int					go_newline(t_prompt *prompt, t_term *term)
{
	int				i;
	int				limit;

	limit = term->con->co;
	i = limit - (prompt->line->cursor % limit);
	limit = i;
	while (i--)
		ft_putchar(' ');
	return (limit);
}

int					finish_searchfield(t_prompt *prompt, t_term *term)
{
	(void)prompt;
	(void)term;
	ft_putstr("': ");
	return (3);
}

void				repos_cursor(int n)
{
	n += 1;
	while (--n)
		ft_term_writetc(TC_LEFT);
}

void				putnstr(char *str, int len)
{
	write(1, str, len);
}

void				write_bsearch(t_term *term, t_prompt *prompt, \
									char *hist_res)
{
	ft_prompt_clean(term);
	ft_prompt_wrupdate(prompt, term);
	write_hist_res(hist_res, term);
}
