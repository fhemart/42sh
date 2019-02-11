/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_brdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 04:29:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/06/04 18:29:12 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

t_brdata	*create_new_brdata(char **ocm, size_t setscount, t_bool bs_escape)
{
	t_brdata		*brdata;
	t_brset			*newset;
	unsigned int	i;

	if (!(brdata = new_brdata(bs_escape)))
		return (NULL);
	i = -1;
	while (++i < setscount)
	{
		newset = new_brset_oc((char**)ocm + (i * 3), ocm[i * 3 + 2]);
		newset->info.index = i;
		bracket_addnewset(brdata, newset);
	}
	return (brdata);
}
