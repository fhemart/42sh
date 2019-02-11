/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bad_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:06:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/04 13:06:26 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

void		print_bad_opt(char *progname, int opt)
{
	ft_putstr_fd(SHELL_NAME": ", 2);
	if (progname)
		ft_putstr_fd(progname, 2);
	ft_putstr_fd(": -", 2);
	ft_putchar_fd(opt, 2);
	ft_putstr_fd(": invalid option\n", 2);
}
