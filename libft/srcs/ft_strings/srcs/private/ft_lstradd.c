/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:01:46 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/03 20:07:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lstr.h"

void	ft_lstradd(t_lstr **str, t_lstr *newstr)
{
	return (ft_lstadd((t_list**)str, (t_list*)newstr));
}
