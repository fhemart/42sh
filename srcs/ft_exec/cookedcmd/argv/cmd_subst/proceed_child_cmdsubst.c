/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_child_cmdsubst.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/20 01:40:18 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static t_bool	is_empty_cmdsubst(char *str)
{
	t_chrmsk	msk;

	msk = new_chrmsk(" \t\n");
	while (char_match_pattern(*(++str), &msk))
		;
	if (*str == ')' && !str[1])
		return (TRUE);
	return (FALSE);
}

void			proceed_child_cmdsubst(char *curr_param, char *src, \
										t_shdata *data)
{
	t_iuser		*iuser;
	int			parse_ret;

	data->is_fork |= IS_CMDSUBST;
	del_inputlist(&data->command);
	iuser = get_cmdsubst_iuser(src, data);
	ft_strdel(&curr_param);
	if (is_empty_cmdsubst(iuser->src))
		parse_ret = FAILURE;
	else
		parse_ret = parse_cmd(iuser, data, SHELL_NAME": "CMD_SUBST_STR": ");
	ft_strdel(&iuser->src);
	if (parse_ret == SUCCESS)
		ft_exec_inputlist(&data->command, data);
	exit_shell(NULL, data, data->last_retval);
}
