/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:33:41 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/03 20:21:11 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"

int		ft_putlstr_fd(t_lstr *str, int fd)
{
	int	ret;

	ret = 0;
	if (str->next)
		ret = ft_putlstr(str->next);
	if (ret != -1)
		ret = write(fd, str->buffer, str->len);
	return (ret);
}
