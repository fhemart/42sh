/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:47:02 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 18:55:59 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"
#include "brackets_private.h"

static void		debug_uinfotop(t_brdata *data)
{
	ft_putstr("[update_info] : src\n  [before] : \"");
	ft_putstr(data->src);
	ft_putstr("\"\n");
}

static void		debug_uinfobot(t_brdata *data)
{
	ft_putstr("   [after] : \"");
	ft_putstr(data->src);
	ft_putstr("\"\n");
}

t_bool			current_is_validescape(t_brdata *data)
{
	t_brinfo	*info;

	if ((info = (t_brinfo*)ft_stack_looktop(data->brstack))
	&& (info->type == BR_ESCAPE && *data->src))
		return (TRUE);
	return (FALSE);
}

t_chrmsk		*skip_escape(t_brdata *data)
{
	t_brinfo	*info;

	data->src++;
	ft_stack_get_content(data->brstack);
	if ((info = (t_brinfo*)ft_stack_looktop(data->brstack)))
		return (&info->expmatch);
	return (&data->start_occ);
}

t_chrmsk		*update_info(t_brdata *data)
{
	t_brinfo	*info;

	if (BRACK_DEBUGPRINT)
		debug_uinfotop(data);
	if ((info = (t_brinfo*)ft_stack_looktop(data->brstack))
	&& ft_strnequ(data->src, info->cl, info->size[BRACK_CLOSE]))
		close_br(data);
	else
		find_openbr(data);
	if ((info = (t_brinfo*)ft_stack_looktop(data->brstack)))
	{
		return (&info->expmatch);
	}
	if (BRACK_DEBUGPRINT)
		debug_uinfobot(data);
	return (&data->start_occ);
}
