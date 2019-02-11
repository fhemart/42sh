/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_snake.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:58:53 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/20 17:10:25 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "snake.h"

static int	check_display_size(t_term_ws *windows_attr)
{
	if (!windows_attr \
	|| windows_attr->ws_col < SNK_MIN_X \
	|| windows_attr->ws_row < SNK_MIN_Y)
		return (FAILURE);
	return (SUCCESS);
}

static void	init_all(t_tc_win *win, t_game_data *gdata)
{
	if (init_snk(win) == FAILURE)
	{
		ft_putstr("init snk failed\n");
		gdata->status = ST_FAILURE;
		return ;
	}
	if (check_display_size(&win->windows_attr) == FAILURE)
	{
		ft_putstr("\e[8;");
		ft_putnbr(SNK_MIN_Y + 1);
		ft_putchar(';');
		ft_putnbr(SNK_MIN_X + 1);
		ft_putstr("t");
		win->windows_attr.ws_col = SNK_MIN_X;
		win->windows_attr.ws_row = SNK_MIN_Y;
		win->resised = 2;
	}
	exec_tc_cap(TC_CURSOR_HIDE);
	init_gamedata(gdata, win);
}

int			builtin_snake(t_cookedcmd *cmd, t_shdata *shdata)
{
	static t_game_data	gdata;
	t_tc_win			win;

	(void)cmd;
	(void)shdata;
	init_all(&win, &gdata);
	while (gdata.status == ST_CONTINUE)
		input_update(&win, &gdata);
	exit_snk(&gdata, &win);
	return (gdata.status == ST_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE);
}
