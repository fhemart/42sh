/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:44:31 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/07 01:23:06 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errormsg.h"

void		p_eloop(char *file, char *head)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": "FT_ELOOP"\n", 2);
}

void		p_ename2long(char *head)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(FT_ENAMETOOLONG, 2);
}

int			p_enonum(char *head, char *nonum)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(nonum, 2);
	ft_putendl_fd(EXIT_ENONUM, 2);
	return (EXIT_FAILURE);
}

int			p_eargreq(char *head, char *usage, int opt)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putchar_fd('-', 2);
	ft_putchar_fd(opt, 2);
	ft_putendl_fd(": " EARGREQ, 2);
	if (usage)
		ft_putendl_fd(usage, 2);
	return (EXIT_FAILURE);
}

int			p_eambr(char *head, char *str)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": " FT_EAMBR "\n", 2);
	return (FAILURE);
}
