/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_destroy_result.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:11:36 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/16 16:06:05 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dictionary.h"

int					ft_dictionary_destroy_result(t_dict_result **result)
{
	if (!result || !*result)
		return (FAILURE);
	free(*result);
	*result = NULL;
	return (SUCCESS);
}
