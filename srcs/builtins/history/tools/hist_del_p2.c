/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_del_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:17:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void		hist_del_book(t_histbook **book)
{
	t_histbook	*dummy;

	if (!(dummy = *book))
		return ;
	ft_strdel(&dummy->filename);
	free(dummy);
	*book = NULL;
}

static void	recurs_del_books(t_histbook *book)
{
	if (!book)
		return ;
	recurs_del_books(book->next);
	hist_del_book(&book);
}

void		hist_del(t_shhist **history)
{
	t_shhist	*dummy;

	if (!(dummy = *history))
		return ;
	hist_del_allentries(&dummy->entries);
	recurs_del_books(dummy->files);
	free(dummy);
	*history = NULL;
}
