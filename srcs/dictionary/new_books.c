/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_books.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 03:42:33 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/04 03:46:07 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "books.h"

t_books				*new_books(void)
{
	t_books			*new_books;

	if (!(new_books = malloc(sizeof(t_books))))
		return (NULL);
	return (new_books);
}
