/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_setcanon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:38:42 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/22 17:58:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

t_bool							ft_iscntrl(int c)
{
	if ((c >= 0 && c <= 31) || c == 127)
		return (TRUE);
	return (FALSE);
}

static int						get_term_answer(void)
{
	char						rettmp;
	int							i;
	int							j;
	int							start;
	int							current_co;

	i = 0;
	j = -1;
	start = 0;
	current_co = 0;
	while (read(0, &rettmp, 1) > 0 && ++j < 30)
	{
		if (ft_iscntrl(rettmp))
			start = 1;
		else if (start > 0)
		{
			if (rettmp == 'R')
				return (current_co);
			if (rettmp == ';')
				start = 2;
			else if (start == 2 && ft_isdigit(rettmp))
				current_co = current_co * 10 + (rettmp - '0');
		}
	}
	return (0);
}

int								ft_term_get_curse_pos(t_term *term)
{
	int							save_vmin;
	int							save_vtime;
	int							tmp;

	ft_term_setcanon(term);
	save_vmin = term->current.c_cc[VMIN];
	save_vtime = term->current.c_cc[VTIME];
	term->current.c_cc[VMIN] = 0;
	term->current.c_cc[VTIME] = 1;
	tcsetattr(0, TCSADRAIN, &term->current);
	ft_putstr("\e[?6n");
	tmp = get_term_answer();
	term->current.c_cc[VMIN] = save_vmin;
	term->current.c_cc[VTIME] = save_vtime;
	ft_term_restore(term);
	return (tmp);
}

void							ft_term_setcanon(t_term *term)
{
	term->current.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
		| INLCR | IGNCR | ICRNL | IXON);
	term->current.c_oflag &= ~OPOST;
	term->current.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	term->current.c_cflag &= ~(CSIZE | PARENB);
	term->current.c_cflag |= CS8;
	tcsetattr(0, TCSADRAIN, &term->current);
	signal(SIGWINCH, ft_term_sighandler);
	term->con = ft_term_sigwinch(term, 0);
}
