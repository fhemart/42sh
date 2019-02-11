/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsd_books.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 06:58:05 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/12 13:42:58 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "books.h"

t_books			*gsd_books(int gsd, t_list *binpath, t_builtin *builtins)
{
	static t_books		new_books;

	if (gsd == FT_STSET)
	{
		destroy_books(&new_books);
		if ((fill_books(&new_books, binpath, builtins) == FAILURE))
			return (NULL);
	}
	else if (gsd == FT_STDEL)
	{
		destroy_books(&new_books);
	}
	return (&new_books);
}
