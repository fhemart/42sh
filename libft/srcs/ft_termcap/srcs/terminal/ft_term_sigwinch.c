/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_sigwinch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:42:02 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 22:22:48 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "ft_prompt.h"
#include "ft_dlist.h"
#include "ft_prompt_private.h"
#include "ftsh.h"

static void			ioctl_exit(t_term *term)
{
	ft_putstr_fd("ioctl: loading failed\n", 2);
	if (term && term->prompt && term->prompt->cparam)
		exit_shell(NULL, ((t_iuser*)term->prompt->cparam)->shdata, 1);
	exit(1);
}

static void			update_size(struct winsize *ws, struct winsize *oldws, \
								t_con *con, t_term *termptr)
{
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, ws) == FAILURE)
		ioctl_exit(termptr);
	oldws->ws_col = con->co;
	oldws->ws_row = con->li;
	ft_term_update_size(con, ws);
	termptr->con = con;
}

static void			load_last_size(struct winsize *oldws, t_con *con)
{
	if (RESIZE_SMOOTH == 1)
	{
		(void)oldws;
		con->lastco = con->co;
		con->lastli = con->li;
	}
	else
	{
		(void)con;
		con->lastco = oldws->ws_col;
		con->lastli = oldws->ws_row;
	}
}

void				exit_bs(t_term *term)
{
	t_prompt		*prompt;

	ft_prompt_ifresise(term);
	if (!(prompt = term->prompt)->inbsearch)
		return ;
	ft_prompt_clr_exitbs_upd(prompt, term, TRUE);
}

t_con				*ft_term_sigwinch(t_term *term, int mode)
{
	static t_term	*termptr;
	struct winsize	ws;
	struct winsize	oldws;
	static t_con	con;

	if (!termptr)
		termptr = term;
	update_size(&ws, &oldws, &con, termptr);
	if (!term)
	{
		exit_bs(termptr);
		load_last_size(&oldws, &con);
		if (ft_prompt_resise(termptr, mode, &ws) == 1)
			return (&con);
		if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == FAILURE)
			ioctl_exit(termptr);
		ft_term_update_size(&con, &ws);
		if (mode == 0 && (con.co != con.lastco \
		|| con.li != con.lastli))
			return (ft_term_sigwinch(NULL, 1));
		ft_prompt_ifresise(termptr);
		if (termptr->cc == 1)
			ft_prompt_resize_write(termptr, &con);
	}
	return (&con);
}
