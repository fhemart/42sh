/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_brdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 04:05:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 18:55:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

t_brdata	*new_brdata(t_bool addbsescape)
{
	t_brdata	*new;
	t_escset	*bs;

	if (!(new = (t_brdata*)ft_memalloc(sizeof(t_brdata))))
		return (NULL);
	if (!(new->brstack = ft_memalloc(sizeof(t_stack))))
	{
		free(new);
		return (NULL);
	}
	if (addbsescape)
	{
		if (!(bs = new_escset("\\")))
		{
			free(new);
			return (NULL);
		}
		else
			bracket_addnewset(new, (t_brset*)bs);
	}
	ft_stack_init(new->brstack, MIN_BRSTACK_HEIGHT);
	return (new);
}
