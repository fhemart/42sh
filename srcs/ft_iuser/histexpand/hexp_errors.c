/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexp_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 17:41:08 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				p_eeventnf(t_histemark *hem)
{
	ft_putstr_fd(SHELL_NAME": !", 2);
	*hem->strend = '\0';
	if (hem->strbegin[1] == '?')
	{
		hem->strbegin++;
		if (hem->strend[-1] == '?')
			hem->strend[-1] = '\0';
	}
	ft_putstr_fd(hem->strbegin + 1, 2);
	ft_putstr_fd(": event not found\n", 2);
	return (FAILURE);
}

int				p_emodnf(char mod)
{
	ft_putstr_fd(SHELL_NAME": ", 2);
	ft_putchar_fd(mod, 2);
	ft_putstr_fd(": unrecognized history modifier\n", 2);
	return (FAILURE);
}

int				p_ebwspec(t_histemark *hem)
{
	char	*prev;

	prev = ft_strchr(hem->strbegin, ':');
	ft_putstr_fd(SHELL_NAME": :", 2);
	*hem->strend = '\0';
	ft_putstr_fd(prev + 1, 2);
	ft_putstr_fd(": bad word specifier\n", 2);
	return (FAILURE);
}

int				p_emsubfail(t_histemark *hem)
{
	size_t		len;

	if (hem->substart[(len = ft_strlen(hem->substart) - 1)] == '\n')
		hem->substart[len] = '\0';
	ft_putstr_fd(SHELL_NAME": ", 2);
	ft_putstr_fd(hem->substart, 2);
	ft_putstr_fd(": substitution failed\n", 2);
	return (ST_FAILURE);
}

int				p_enopsub(void)
{
	ft_putstr_fd(SHELL_NAME ": &: no previous substitution\n", 2);
	return (ST_FAILURE);
}
