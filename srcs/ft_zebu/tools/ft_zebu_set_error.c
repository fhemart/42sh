/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zebu_set_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:17:13 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 15:01:17 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

int			ft_zebu_set_error(t_tkn_factory *factory)
{
	factory->main_status = TF_STATUS_ERROR;
	return (0);
}
