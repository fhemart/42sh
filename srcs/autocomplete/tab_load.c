/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:37:06 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 11:00:45 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

static char			refine_word_quote(char quote, char c, int *i)
{
	*i += 1;
	if (quote == 0)
	{
		return (c);
	}
	else if (quote == c)
		return (0);
	else if (quote != 0)
		*i -= 1;
	return (quote);
}

static int			refine_word_backslash(char *str, int quote)
{
	t_chrmsk		msk;

	(void)msk;
	if (quote == 0)
	{
		if (str + 1 && *str + 1 == 'n')
			return (2);
		return (1);
	}
	else if (quote == '"')
	{
		msk = ft_msk_new_chrmsk(TAB_INDQUO);
		if (str + 1 && ft_msk_char_match_pattern(*(str + 1), &msk))
			return (1);
	}
	return (0);
}

static int			tab_refine_word(t_tab *state, char *str)
{
	int				len;
	int				i;
	int				j;
	char			quote;
	char			buff[1024];

	len = (state->current - state->begin) + 1;
	i = 0;
	j = 0;
	quote = 0;
	state->chrmsk = ft_msk_new_chrmsk(FNTAB_STR);
	while (i < len)
	{
		if (ft_msk_char_match_pattern(str[i], &state->chrmsk))
			quote = refine_word_quote(quote, str[i], &i);
		if (str[i] == '\\')
			i += refine_word_backslash(&str[i], quote);
		if (i < len)
			buff[j++] = str[i++];
	}
	buff[j] = '\0';
	str = ft_strcpy(str, buff);
	return (SUCCESS);
}

static void			tab_load_debug(t_tab *state, char *buff)
{
	if (state->status == 1)
		ft_term_debug_putfd("COMMAND");
	else
		ft_term_debug_putfd("PARAM");
	if (state->quotedmode != 0)
		ft_term_debug_putfd("QUOTED");
	ft_term_debug_putfd("RAFFINED WORD");
	ft_term_debug_putfd(buff);
}

int					tab_load(t_tab *state, t_term *term)
{
	char			buff[1024];
	t_cell			*curs;
	int				i;
	int				j;

	i = 0;
	j = 0;
	ft_bzero(&buff, 1024);
	curs = term->prompt->line->head;
	while (curs)
	{
		if (i >= state->begin && i < state->current)
			buff[j++] = curs->c;
		i++;
		curs = curs->next;
	}
	buff[j] = '\0';
	tab_refine_word(state, buff);
	if (PROMPT_DEBUG)
		tab_load_debug(state, buff);
	tab_request(buff, state, term);
	return (SUCCESS);
}
