/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_print_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:26:09 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 11:44:45 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

void				erase_word(t_books *books, t_term *term, t_tab *state, \
							int index)
{
	int				i;

	(void)books;
	i = 0;
	while (i < state->writed || (state->writed == 0 && i < index))
	{
		ft_control_delette(term->prompt, term);
		i++;
	}
}

int					get_pageprint(t_term *term, t_books *books, int *pp)
{
	pp[PP_COL] = term->con->co / (books->allmaxlen + 2);
	if (pp[PP_COL] == 0)
		pp[PP_COL] = 1;
	pp[PP_LI] = books->allcount / pp[PP_COL];
	if (books->allcount % pp[PP_COL] > 0)
		pp[PP_LI]++;
	pp[PP_LIMIT] = pp[PP_LI] + \
	((term->prompt->line->current) ? term->prompt->line->current->li : 0);
	if (pp[PP_LIMIT] < term->con->li)
		return (TRUE);
	return (FALSE);
}

int					load_resultinfo(t_books *books, t_dict_result *result)
{
	t_word			*curs;
	int				i;
	int				limit;

	i = 0;
	limit = result->count;
	curs = result->result;
	books->allcount = 0;
	books->allmaxlen = 0;
	while (i < limit || (limit == 0 && curs))
	{
		books->allcount++;
		if (books->allmaxlen < (int)curs->len)
			books->allmaxlen = curs->len;
		i++;
		curs = curs->next;
	}
	return (SUCCESS);
}

int					print_word(t_word *elem, t_books *books)
{
	size_t			l;
	int				i;

	l = -1;
	i = -1;
	ft_putstr(elem->word);
	while (++l < (books->allmaxlen + 2) - elem->len)
		ft_putchar(' ');
	return (SUCCESS);
}

t_word				*get_next_word(t_word *word, t_dict_result *result)
{
	int				i;

	i = 0;
	while (++i <= result->checked)
		word = word->next;
	return (word);
}
