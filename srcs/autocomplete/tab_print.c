/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:23:13 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/20 15:51:19 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

static int			if_print_continue(int *line, t_term *term)
{
	(*line)++;
	if (*line == term->con->li - 2)
		return (FALSE);
	return (TRUE);
}

static int			pause_print(t_term *term, int *line)
{
	char			c;

	c = 0;
	ft_term_setcanon(term);
	if (read(0, &c, 1) == -1)
		return (FALSE);
	ft_term_restore(term);
	if (c == 'q')
		return (FALSE);
	*line = 0;
	return (TRUE);
}

static int			print_newline(int k, int *line, t_term *term, int col)
{
	if (k % col == 0)
	{
		ft_putchar('\n');
		if (!if_print_continue(line, term) && !pause_print(term, line))
			return (FALSE);
	}
	return (TRUE);
}

int					print_result_page(t_word *elem, int col, t_term *term, \
									t_books *books)
{
	t_word			*curs;
	int				k;
	int				i;
	int				line;

	line = 0;
	k = 0;
	i = 0;
	curs = elem;
	ft_term_restore(term);
	while (curs)
	{
		if ((books->result && books->result->count != 0 \
		&& i == books->result->count) || !print_newline(k, &line, term, col))
			break ;
		print_word(curs, books);
		k++;
		curs = curs->next;
		i++;
	}
	ft_putchar('\n');
	ft_term_setcanon(term);
	ft_prompt_wrupdate(term->prompt, term);
	books->writed = 1;
	return (SUCCESS);
}

int					print_result(t_term *term, t_word *word, t_tab *state, \
								t_dict_result *result)
{
	int				i;

	i = 0;
	term->prompt->hasauto = 1;
	while (word->word[i])
		ft_prompt_printable_key(term->prompt, term, (word->word)[i++]);
	if (tab_ifdir(state, term, word->word, 0) == FALSE && state->quoted)
		ft_prompt_printable_key(term->prompt, term, state->quotedmode);
	term->prompt->hasauto = 0;
	state->writed += ft_strlen(word->word);
	result->checked++;
	return (SUCCESS);
}
