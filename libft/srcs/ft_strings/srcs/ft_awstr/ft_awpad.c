/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_awpad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 02:03:26 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 02:07:41 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_awstr.h"

t_awpad	ft_awpad(char c, size_t height)
{
	t_awpad ret;

	ret = (t_awpad){c, height};
	return (ret);
}
