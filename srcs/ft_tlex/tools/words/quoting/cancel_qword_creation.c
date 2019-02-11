/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancel_qword_creation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 02:06:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/07 14:46:27 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

static void	print_eueof(char *errhead, char *cl)
{
	if (!errhead)
		return ;
	ft_putstr_fd(errhead, 2);
	ft_putstr_fd("unexpected EOF while looking for matching `", 2);
	ft_putstr_fd(cl, 2);
	ft_putstr_fd("'\n", 2);
}

void		cancel_qword_creation(t_tlexicon *tlex, t_br_return *br_ret)
{
	t_brinfo	*info;
	char		*errhead;

	errhead = tlex->errhead;
	if (br_ret && br_ret->status == BR_ABORTED)
	{
		info = (t_brinfo*)ft_stack_looktop(br_ret->opened_quotes);
		if (info->type == BR_QUOTE)
			print_eueof(errhead, info->cl);
	}
	destroy_br_return(&br_ret, FALSE);
	if (errhead)
	{
		ft_putstr_fd(errhead, 2);
		ft_putendl_fd("syntax error: unexpected end of file", 2);
	}
	tlex->main_status = TF_STATUS_ERROR;
}
