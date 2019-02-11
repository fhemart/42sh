/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:26:56 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/14 19:45:22 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"

int			ft_dictionary_new(t_dictionary **dictionary)
{
	if (*dictionary)
		ft_dictionary_destroy(dictionary);
	if (!(*dictionary = malloc(sizeof(t_dictionary))))
	{
		*dictionary = NULL;
		return (FAILURE);
	}
	ft_bzero(*dictionary, sizeof(t_dictionary));
	return (SUCCESS);
}
