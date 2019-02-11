/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 12:17:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/04 18:16:15 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void	exit_shell(t_cookedcmd *cmd, t_shdata *shdata, int exit_status)
{
	cookedcmd_del(&cmd);
	clean_input();
	ft_zebu_exit();
	destroy_books(shdata->books);
	ft_memdel((void**)shdata->books);
	if (isatty(0) && isatty(1) && !(shdata->is_fork & PRINT_PS))
		close_tc(&shdata->term);
	shdata_destroy(shdata);
	_exit(exit_status);
}
