/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zebu_notokleft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:58:01 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/04 15:27:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_bool		ft_zebu_notokleft(t_tkn_factory *factory)
{
	if (fill_container(factory) == TF_CONTINUE)
		return (FALSE);
	return (TRUE);
}
