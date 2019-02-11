/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zebu_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:25:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/09 17:50:08 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

static void		reinit_errmsg(void)
{
	char	*msg;

	msg = (char*)ft_zebu_get_errmsg();
	*msg = '\0';
}

t_tfreturn		*ft_zebu_start(t_tlexicon *tlex, char *src, void *customparam)
{
	static void			(*factory_mode[2])(t_tkn_factory*) = {factory_analyze, \
															factory_ending};
	t_tkn_factory		factory;
	static t_tfreturn	ret;

	ft_bzero(&ret, sizeof(ret));
	reinit_errmsg();
	ft_tlex_resetsrc(tlex, src);
	ft_tlex_fill(tlex);
	if ((ret.final_status = tlex->main_status) == TF_STATUS_ERROR)
		return (&ret);
	factory_init(&factory, tlex, customparam);
	while (factory.main_status < TF_STATUS_ERROR)
		factory_mode[factory.main_status](&factory);
	factory_close(&factory, &ret);
	return (&ret);
}
