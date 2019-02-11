/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 22:30:02 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		parse_cmd(t_iuser *iuser, t_shdata *data, char *errhead)
{
	t_tfreturn	*tfret;

	if (ft_strisspace(iuser->src))
		return (SUCCESS);
	tfret = ft_zebu_start(iuser->tlex, iuser->src, iuser);
	if (!tfret || tfret->final_status == TF_STATUS_ERROR)
	{
		print_sh_parse_error(data, errhead);
		return (FAILURE);
	}
	data->command = tfret->reduced;
	return (SUCCESS);
}
