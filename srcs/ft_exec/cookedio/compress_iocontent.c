/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_iocontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:59:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 21:08:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int		compress_iocontent(t_cookedio *cookedio, t_iocontent *ioctt)
{
	static int		(*redir[7])(int, char*, t_cookedio*) = {
											iof_less, iof_lgand, \
											iof_great, iof_lgand, \
											iof_dgreat, iof_heredoc, \
											iof_heredoc};

	if (!ioctt)
		return (SUCCESS);
	else if (compress_iocontent(cookedio, ioctt->next) == FAILURE)
		return (FAILURE);
	if (redir[ioctt->type](ioctt->ionumber, ioctt->str, cookedio) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
