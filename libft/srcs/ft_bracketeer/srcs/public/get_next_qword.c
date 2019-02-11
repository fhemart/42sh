/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_qword.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 03:45:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/30 03:38:09 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

t_br_return	*get_next_qword(t_brdata *data)
{
	t_br_return		*br_ret;
	char			*start;
	t_chrmsk		*occ;
	t_brinfo		*info;

	if (!(start = data->src) || !*start
	|| !(br_ret = new_br_return(data)))
		return (NULL);
	occ = check_firstchar(data);
	if (!(info = (t_brinfo*)ft_stack_looktop(br_ret->opened_quotes)))
		br_ret->parsed_src = find_next_quote(data, start);
	else if (info->type == BR_QUOTE)
		br_ret->parsed_src = find_next_closure(data, occ, start);
	else if (info->type == BR_ESCAPE)
		br_ret->parsed_src = close_escaping(data, start);
	if (br_ret->parsed_src && !ft_stack_isempty(br_ret->opened_quotes))
		return (try_extend(data, br_ret));
	close_br_return(br_ret);
	return (br_ret);
}
