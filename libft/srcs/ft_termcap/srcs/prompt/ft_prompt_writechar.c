/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_writechar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:38:24 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 01:16:48 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "autocomplete.h"

static int			get_balise_color(char c, int color_index)
{
	if (c == ';' || c == '|' || c == '&' || c == '$')
		color_index = 5;
	else if (c == '(' || c == ')' || c == '{' || c == '}' \
			|| c == '[' || c == ']' || c == '`')
		color_index = 6;
	else if (c == '<' || c == '>')
		color_index = 2;
	else if (c == '"')
		color_index = 3;
	else if (c == '\'')
		color_index = 7;
	else if (c == ' ')
		color_index = 0;
	return (color_index);
}

static int			get_color(t_prompt *prompt, t_term *term, t_tab *state, \
								t_cell *current)
{
	int				color_index;

	(void)term;
	(void)prompt;
	color_index = 0;
	if (state->status == 1)
		color_index = 1;
	else if (state->quoted)
		color_index = state->quotedmode == '\'' ? 7 : 3;
	else if (state->status == 2)
		color_index = 4;
	color_index = get_balise_color(current->c, color_index);
	return (color_index);
}

static int			fill_state(t_prompt *prompt, t_term *term, t_tab *state, \
								t_cell *current)
{
	t_cell			*dummy;

	ft_bzero(state, sizeof(t_tab));
	state->chrmsk = ft_msk_new_chrmsk(FNTAB_STR);
	dummy = prompt->line->current;
	state->curs = prompt->line->head;
	prompt->line->current = current;
	while (state->curs)
	{
		tab_anal(prompt, term, state->curs->c, state);
		if (state->curs && state->curs == current)
		{
			prompt->line->current = dummy;
			return (SUCCESS);
		}
		if (state->curs)
		{
			state->curs = state->curs->next;
			state->current++;
		}
	}
	prompt->line->current = dummy;
	return (SUCCESS);
}

static int			write_color(t_prompt *prompt, t_term *term, t_cell *current)
{
	static char		*colors[8] = {"\x1B[0m", "\e[1;38;5;197m", "\x1B[32m", \
								"\e[1;38;5;154m", "\e[1;38;5;141m", \
								"\e[1;38;5;117m", "\x1B[36m", "\e[1;38;5;202m"};
	t_tab			state;
	int				color_index;

	ft_bzero((void*)&state, sizeof(t_tab));
	fill_state(prompt, term, &state, current);
	color_index = get_color(prompt, term, &state, current);
	if (color_index < 8)
		ft_putstr(colors[color_index]);
	return (color_index);
}

int					ft_prompt_writechar(t_cell *current, t_term *term, \
											t_prompt *prompt)
{
	int				color;

	color = 0;
	if (prompt->color && !prompt->inbsearch)
		color = write_color(prompt, term, current);
	ft_putchar(current->c == '\t' ? ' ' : current->c);
	if (prompt->color)
		ft_putstr("\x1B[0m");
	return (SUCCESS);
}
