/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 06:21:00 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 16:26:07 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int				if_min_size(t_term *term)
{
	t_con		*con;

	con = term->con;
	if (con->li < 4)
		return (TRUE);
	return (FALSE);
}

void			wait_for_min_size(t_term *term, struct winsize *ws)
{
	ft_term_writetc(TC_CARRET);
	ft_term_writetc(TC_DELTOEND);
	ft_putstr("\nScreen to small");
	ft_term_readkey();
	ft_prompt_clean(term);
	resize_smooth(term, ws, 1);
}

void			block_input(t_term *term)
{
	if (term->toosmall == 1)
		return ;
	if (term->mode != 2)
	{
		ft_prompt_clean(term);
		ft_term_writetc(TC_CARRET);
		ft_term_writetc(TC_LEFT);
	}
	else if (term->mode == 2)
	{
		ft_prompt_clean(term);
		ft_term_writetc(TC_INTE);
		ft_prompt_cleanscren(term);
		term->mode = 1;
	}
	ft_term_writetc(TC_CARRET);
	ft_term_writetc(TC_DELTOEND);
	ft_putstr("\nPress any key ...");
	ft_term_readkey();
	ft_prompt_clean(term);
}

static void		resize_nm(t_term *termptr, int mode)
{
	if (termptr->enterhit % 2 == 0)
	{
		if (mode == 0 || (mode == 1 && termptr->cc == 0))
		{
			block_input(termptr);
			termptr->cc = 1;
		}
	}
	termptr->enterhit += 1;
}

int				ft_prompt_resise(t_term *termptr, int mode, struct winsize *ws)
{
	if (RESIZE_SMOOTH == 1)
	{
		resize_smooth(termptr, ws, 0);
		return (TRUE);
	}
	else
		resize_nm(termptr, mode);
	return (FALSE);
}
