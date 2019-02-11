/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:44:31 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:59:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errormsg.h"

void		p_enotf(char *head, char *name)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": not found\n", 2);
}

void		p_enoent(char *file, char *head)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": "FT_ENOENT"\n", 2);
}

void		p_enotdir(char *file, char *head)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": "FT_ENOTDIR"\n", 2);
}

void		p_eisdir(char *file, char *head)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": "FT_EISDIR"\n", 2);
}

void		p_eacces(char *file, char *head)
{
	if (head)
		ft_putstr_fd(head, 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": "FT_EACCES"\n", 2);
}
