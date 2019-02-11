/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putawstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 02:03:26 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 02:57:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_awstr.h"

int		ft_putawstr(t_awstr *str)
{
	int		ret_value;

	ret_value = (int)str->size;
	write(1, str->buffer, str->size);
	str->size = 0;
	return (ret_value);
}
