/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:38:46 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/14 18:15:02 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int			ft_control_clear(t_prompt *prompt, t_term *term)
{
	(void)prompt;
	if (prompt->inbsearch)
		ft_prompt_exit_bsearch(term, TRUE);
	ft_prompt_clean(term);
	ft_term_writetc(TC_CLEAR);
	ft_prompt_wrupdate(prompt, term);
	return (TRUE);
}
