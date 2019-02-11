/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnqw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 03:45:18 by jbulant           #+#    #+#             */
/*   Updated: 2018/09/28 20:51:21 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

t_br_return	*new_br_return(t_brdata *data)
{
	t_br_return	*new;

	if (!(new = (t_br_return*)ft_memalloc(sizeof(t_br_return))))
		return (NULL);
	new->opened_quotes = data->brstack;
	return (new);
}

t_chrmsk	*check_firstchar(t_brdata *data)
{
	t_brinfo	*binfo;

	if ((binfo = (t_brinfo*)ft_stack_looktop(data->brstack))
	&& binfo->type == BR_QUOTE)
		return (&binfo->expmatch);
	if (current_is_validescape(data))
		return (&data->start_occ);
	if (char_match_pattern(*data->src, &data->start_occ)
	&& !is_closedbr(data, data->src))
		return (update_info(data));
	return (brdata_get_firstmsk(data));
}

void		close_br_return(t_br_return *br_ret)
{
	if (br_ret->parsed_src)
		br_ret->parsed_size = ft_strlen(br_ret->parsed_src);
	else
		br_ret->parsed_size = 0;
	if (ft_stack_isempty(br_ret->opened_quotes))
		br_ret->status = BR_SUCCESS;
}

void		destroy_br_return(t_br_return **br_ret, t_bool keep_parsed)
{
	if (!*br_ret)
		return ;
	if (!keep_parsed && (*br_ret)->parsed_src)
		free((*br_ret)->parsed_src);
	free(*br_ret);
	*br_ret = NULL;
}
