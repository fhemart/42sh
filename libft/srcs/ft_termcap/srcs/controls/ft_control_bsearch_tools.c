/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_bsearch_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 04:12:29 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 04:18:55 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"

char			*get_hist_currline_mod(t_iuser *iuser)
{
	t_shhist	*hist;

	hist = iuser->shdata->history;
	return (hist_get_modified(hist->current_histline));
}

void			hist_validate_bsearch(t_iuser *iuser)
{
	t_shhist	*hist;

	hist = iuser->shdata->history;
	hist->current_histline = hist->last_bsentry;
}

int				ft_prompt_clr_exitbs_upd(t_prompt *prompt, t_term *term, \
											t_bool restore)
{
	ft_prompt_clean(term);
	ft_prompt_exit_bsearch(term, restore);
	ft_prompt_wrupdate(prompt, term);
	return (SUCCESS);
}
