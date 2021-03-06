/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:28:06 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/21 13:26:26 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_ishexdec(char c)
{
	return (ft_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}
