/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_parent_cmdsubst.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/24 16:08:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			proceed_parent_cmdsubst(t_wexpinf *weinf, char *src, t_shdata *data)
{
	t_iuser		*iuser;

	iuser = new_iuser("", data);
	if (*src != '`')
		src--;
	weinf->src = weinf->src_cmdsubst;
	weinf->save_src = get_next_closure(iuser->brdata, src);
	if ((weinf->save_state = weinf->state) & SET_DQUMODE)
		weinf->state = WEXP_DQUBQUMSK;
	else
		weinf->state = WEXP_BQUMSK;
	weinf->parsed_subst = 1;
	return (ST_CONTINUE);
}
