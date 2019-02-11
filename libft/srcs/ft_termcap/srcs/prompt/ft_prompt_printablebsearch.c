/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_printablebsearch.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 09:40:51 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 09:48:33 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"
#include "ftsh.h"

void				write_hist_res(char *res, t_term *term)
{
	int				nbret;
	int				limit;
	int				len;

	limit = term->con->co * (term->con->li - 2);
	len = ft_strlen(res);
	nbret = finish_searchfield(term->prompt, term);
	if (len > limit)
	{
		nbret += limit - 3;
		putnstr(res, nbret);
		ft_putstr("...");
		nbret += 6;
	}
	else
	{
		nbret += ft_strlen(res);
		ft_putstr(res);
	}
	repos_cursor(nbret);
}

char				*find_entry(t_shdata *data, char *tofind)
{
	t_histentry		*bsentry;

	bsentry = data->history->last_bsentry;
	if (!tofind || !*tofind)
		return (hist_get_modified(bsentry));
	if (!bsentry && !(bsentry = data->history->entries))
		return (NULL);
	if ((bsentry = hist_get_strstr(bsentry, tofind)))
		data->history->last_bsentry = bsentry;
	return (hist_get_modified(bsentry));
}

char				*find_next_entry(t_shdata *data, char *tofind)
{
	t_histentry		*bsentry;
	char			*last;

	bsentry = data->history->last_bsentry;
	last = hist_get_modified(bsentry);
	if (!tofind || !*tofind)
		return (last);
	if (!bsentry && !(bsentry = data->history->entries))
		return (NULL);
	if ((bsentry = hist_get_strstr(bsentry->prev, tofind)))
	{
		data->history->last_bsentry = bsentry;
		return (hist_get_modified(bsentry));
	}
	return (last);
}

int					bsearch_next(t_prompt *prompt, t_term *term)
{
	char			*str;
	char			*hist_res;

	str = ft_dlist2str(prompt->line);
	hist_res = find_next_entry(((t_iuser*)prompt->cparam)->shdata, str);
	ft_strdel(&str);
	if (!hist_res)
		return (SUCCESS);
	ft_prompt_clean(term);
	ft_prompt_wrupdate(prompt, term);
	write_hist_res(hist_res, term);
	return (SUCCESS);
}

int					print_in_bsearch(t_prompt *prompt, t_term *term, \
									char key)
{
	t_line			*line;
	char			*str;
	char			*hist_res;

	line = prompt->line;
	if (term->mode == MODE_TRUNC)
		return (SUCCESS);
	if (prompt->line->nbelem + 1 >= term->con->co)
	{
		ft_putchar(7);
		return (SUCCESS);
	}
	ft_dlist_addnode(prompt->line, key, prompt->pool);
	str = ft_dlist2str(prompt->line);
	hist_res = find_entry(((t_iuser*)prompt->cparam)->shdata, str);
	ft_strdel(&str);
	if (!hist_res)
	{
		ft_dlist_rmnode(prompt->line, prompt->pool);
		return (SUCCESS);
	}
	line->cursor += 1;
	line->lastmove = CURSMOVE_AUTO;
	write_bsearch(term, prompt, hist_res);
	return (SUCCESS);
}
