/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdata_resetsrc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 04:03:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/28 20:50:45 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

void		brdata_resetsrc(t_brdata *data, char *src)
{
	data->src = src;
	ft_stack_reset(data->brstack);
}
