/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:11:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 17:13:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

void		setenv_envid(char *name)
{
	ft_putstr_fd(SHELL_NAME": '", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("'"SETENV_ENVID"\n", 2);
}

void		unsetenv_id_doesntexist(char *name)
{
	ft_putstr_fd(SHELL_NAME": '", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("'"UNSETENV_IDDNE"\n", 2);
}
