/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 01:16:35 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/16 16:08:35 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"

t_dict_result		*dictionary_new_result(void)
{
	t_dict_result	*newres;

	if (!(newres = malloc(sizeof(t_dict_result))))
		return (NULL);
	ft_bzero(newres, sizeof(t_dict_result));
	return (newres);
}

static int			dictionary_check_word(t_dictionary *dictionary, \
											char *tosearch, size_t len)
{
	int				index;
	t_word			*curs;

	if ((index = dictionary_get_index(*tosearch)) == FAILURE)
		return (FAILURE);
	curs = dictionary->indexes[index];
	if (dictionary->result)
		ft_dictionary_destroy_result(&dictionary->result);
	while (curs)
	{
		if (ft_strncmp(curs->word, tosearch, len) == 0)
		{
			if (!dictionary->result \
				&& !(dictionary->result = dictionary_new_result()))
				return (FAILURE);
			ft_bzero(dictionary->result, sizeof(t_dict_result));
			dictionary->result->result = curs;
			return (TRUE);
		}
		curs = curs->next;
	}
	return (FALSE);
}

int					ft_dictionary_get(t_dictionary *dictionary, \
						char *tosearch, size_t len)
{
	int				ret;
	t_word			*curs;

	curs = NULL;
	if (!dictionary || !tosearch || len == 0)
		return (FAILURE);
	ret = dictionary_check_word(dictionary, tosearch, len);
	if (ret == 1)
	{
		curs = dictionary->result->result;
		while (curs)
		{
			if ((ft_strncmp(tosearch, curs->word, len)) == 0)
				dictionary->result->count++;
			else
				break ;
			curs = curs->next;
		}
	}
	return (ret);
}
