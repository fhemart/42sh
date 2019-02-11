/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_find_book.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:10:48 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_histbook	*hist_find_book(t_histbook *head, char *fname)
{
	while (head)
	{
		if (ft_strequ(head->filename, fname))
			break ;
		head = head->next;
	}
	return (head);
}
