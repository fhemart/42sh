/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 21:39:23 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 11:45:55 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "books.h"

int				destroy_bin(t_dictionary **bin)
{
	ft_dictionary_destroy((t_dictionary**)bin);
	return (SUCCESS);
}
