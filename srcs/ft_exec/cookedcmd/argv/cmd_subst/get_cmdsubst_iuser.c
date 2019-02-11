/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdsubst_iuser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 22:29:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_iuser		*get_cmdsubst_iuser(char *src, t_shdata *data)
{
	static char	errhead[] = SHELL_NAME": "CMD_SUBST_STR": ";
	t_br_return	*br_ret;
	t_iuser		*iuser;

	iuser = new_iuser("", data);
	iuser->tlex->errhead = errhead;
	src = *src == '`' ? src : src - 1;
	brdata_updatesrc(iuser->brdata, src);
	br_ret = get_next_qword(iuser->brdata);
	src = br_ret->parsed_src;
	*src = *src == '`' ? '(' : ' ';
	src[br_ret->parsed_size - 1] = ')';
	iuser->src = src;
	destroy_br_return(&br_ret, TRUE);
	return (iuser);
}
