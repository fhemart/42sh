/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_exptoken.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 10:32:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 13:57:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

t_exptoken		*new_exptoken(int id, t_tkn_expr *model)
{
	t_exptoken		*new;

	if (!id_isexpr(id) || !(new = ft_pool_get(get_exptoken_pool(FT_STGET))))
		return (NULL);
	new->id = id;
	new->rules = model->rules;
	new->maxstate = model->isc;
	new->validstate = TF_UNVALIDSTATE;
	new->isrecursive = FALSE;
	new->tsoffset = 0;
	return (new);
}
