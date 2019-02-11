/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 04:04:39 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/14 18:15:51 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "books.h"

int				fill_bin(t_books *books, t_list *binpath)
{
	if (!books)
		return (FAILURE);
	if ((ft_dictionary_new((t_dictionary**)&books->bin)) == FAILURE)
		return (FAILURE);
	if (ft_hashtable_new(&books->hashtable) == -1)
		return (FAILURE);
	if (!binpath)
		return (SUCCESS);
	return (parse_bin(books->bin, books->hashtable, binpath));
}
