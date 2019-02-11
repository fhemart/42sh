/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 02:06:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/20 12:36:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

t_lstr	*reduce_word(char **src, t_lstr *str, int index)
{
	str = ft__strncat(&str, *src, index);
	*src += index;
	return (str);
}
