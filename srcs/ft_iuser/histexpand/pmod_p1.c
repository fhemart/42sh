/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmod_p1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:00:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 17:29:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				pmodh(t_histemark *hem)
{
	char	*head;

	if ((head = ft_strrchr(hem->replace, '/')))
		*head = '\0';
	return (SUCCESS);
}

int				pmodt(t_histemark *hem)
{
	char	*tail;

	if ((tail = ft_strrchr(hem->replace, '/')))
		ft_strcpy(hem->replace, tail);
	return (SUCCESS);
}

int				pmodr(t_histemark *hem)
{
	char	*suffix;

	if ((suffix = ft_strrchr(hem->replace, '.')))
		*suffix = '\0';
	return (SUCCESS);
}

int				pmode(t_histemark *hem)
{
	char	*suffix;

	if ((suffix = ft_strrchr(hem->replace, '.')))
		ft_strcpy(hem->replace, suffix);
	return (SUCCESS);
}

int				pmodp(t_histemark *hem)
{
	hem->donotexec = TRUE;
	return (SUCCESS);
}
