/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlex_addwpolish.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/06 10:47:32 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

int			ft_tlex_addwpolish(int (*action)(t_tlexicon*, t_token*, void*), \
								void *param, t_tlexicon *tlex)
{
	t_wordpolish	*wpolish;

	if (!tlex || !(wpolish = (t_wordpolish*)ft_memalloc(sizeof(t_wordpolish))))
		return (-1);
	wpolish->action = action;
	wpolish->param = param;
	tlex->wpolish = wpolish;
	return (0);
}
