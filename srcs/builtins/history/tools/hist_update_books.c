/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_update_books.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 19:10:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void		hist_update_books(t_shhist *hist, char *histfile, int line_read)
{
	t_histbook		*book;

	if ((book = hist_find_book(hist->files, histfile)))
		book->line_read = line_read;
	else if ((book = hist_new_book(histfile, line_read)))
		ft_lstadd((t_list**)&hist->files, (t_list*)book);
}
