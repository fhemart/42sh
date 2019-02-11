/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_cleanernew.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:34:47 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/06 23:34:56 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack_cleaner	*ft_stack_cleanernew(void *content, \
									size_t content_size, size_t count)
{
	t_stack_cleaner *ret;

	if (!(ret = (t_stack_cleaner*)ft_memalloc(sizeof(t_stack_cleaner))))
		return (NULL);
	ret->from = content;
	ret->to = content + (content_size * count);
	ret->count = count;
	return (ret);
}
