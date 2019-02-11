/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_books.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 03:49:55 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/14 17:53:41 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "books.h"

int				fill_books(t_books *books, t_list *binpath, t_builtin *builtins)
{
	if (!books || !builtins)
		return (FAILURE);
	if ((fill_bin(books, binpath)) == FAILURE)
	{
		destroy_books(books);
		return (FAILURE);
	}
	if ((fill_builtins(books, builtins)) == FAILURE)
	{
		destroy_books(books);
		return (FAILURE);
	}
	if ((fill_all(books, books->bin, books->builtins)) == FAILURE)
	{
		destroy_books(books);
		return (FAILURE);
	}
	return (SUCCESS);
}
