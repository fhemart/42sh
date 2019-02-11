/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_resize_smooth.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:21:45 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 22:22:55 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ftsh.h"

static void	ioctl_exit(t_term *term)
{
	ft_putstr_fd("ioctl: loading failed\n", 2);
	if (term && term->prompt && term->prompt->cparam)
		exit_shell(NULL, ((t_iuser*)term->prompt->cparam)->shdata, 1);
	exit(1);
}

void		resize_smooth(t_term *termptr, struct winsize *ws, char mode)
{
	if (termptr->mode == MODE_TRUNC || if_min_size(termptr) == TRUE)
	{
		if (termptr->enterhit % 2 == 0 && mode == 0)
			block_input(termptr);
		termptr->enterhit += 1;
		if (ioctl(STDIN_FILENO, TIOCGWINSZ, ws) == FAILURE)
			ioctl_exit(termptr);
		ft_prompt_ifresise(termptr);
		ft_term_update_size(termptr->con, ws);
		if (if_min_size(termptr) == TRUE)
		{
			termptr->toosmall = 1;
			wait_for_min_size(termptr, ws);
			termptr->toosmall = 0;
		}
		else
		{
			ft_prompt_clean(termptr);
			ft_prompt_wrupdate(termptr->prompt, termptr);
		}
	}
}
