/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 20:44:26 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 11:47:05 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "books.h"
#include "builtins_private.h"

int				fill_builtins(t_books *books, t_builtin *builtin)
{
	int			i;

	i = -1;
	if ((ft_dictionary_new(&books->builtins)) == FAILURE)
		return (FAILURE);
	while (++i < BUILTINS_COUNT)
	{
		if ((ft_dictionary_addword(NULL, builtin[i].name, \
			books->builtins)) == FAILURE)
		{
			ft_dictionary_destroy(&books->builtins);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
