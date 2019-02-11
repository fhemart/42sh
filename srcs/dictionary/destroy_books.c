/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_books.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 21:50:33 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/02 15:19:57 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "books.h"

static t_bool	need_destroy_result(t_books *books)
{
	t_dict_result	*dicktracy;

	dicktracy = books->result;
	if (!dicktracy
	|| ((books->bin && dicktracy == books->bin->result)
	|| (books->builtins && dicktracy == books->builtins->result)
	|| (books->onetime && dicktracy == books->onetime->result)
	|| (books->onetimeall && dicktracy == books->onetimeall->result)
	|| (books->all && dicktracy == books->all->result)))
		return (FALSE);
	return (TRUE);
}

int				destroy_books(t_books *books)
{
	t_bool		destroy_res;

	destroy_res = need_destroy_result(books);
	ft_dictionary_destroy(&books->bin);
	ft_dictionary_destroy(&books->builtins);
	ft_dictionary_destroy(&books->onetime);
	ft_dictionary_destroy(&books->onetimeall);
	ft_dictionary_destroy(&books->all);
	ft_hashtable_destroy(&books->hashtable, hashtable_destroy_content);
	if (destroy_res == FALSE)
		books->result = NULL;
	else
		ft_dictionary_destroy_result(&books->result);
	return (SUCCESS);
}
