/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_set_error_msg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:56:38 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 23:05:04 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zebu_core.h"

static void		copy_msg(char *emsg, char *tokstr)
{
	if (!tokstr)
		return ;
	if (ft_strlen(tokstr) < 88)
		ft_strcat(emsg, tokstr);
	else
	{
		ft_strncat(emsg, tokstr, 84);
		ft_strcat(emsg, "...");
	}
}

void			factory_set_error_msg(t_tkn_factory *factory)
{
	t_token		*dummy;
	char		*emsg;
	char		*tokstr;

	emsg = (char*)ft_zebu_get_errmsg();
	if (!factory->lex->errhead)
	{
		emsg[0] = '\0';
		return ;
	}
	if (!(dummy = factory->tokencontainer))
	{
		ft_strcpy(emsg, TFACTORY_ERR_EOF"\n");
		return ;
	}
	ft_strcpy(emsg, TFACTORY_ERR_UET);
	if (dummy->type == ft_tlex_gword(factory->lex))
		tokstr = dummy->content;
	else
		tokstr = tkn_tostring(factory->grammar, dummy->type);
	copy_msg(emsg, tokstr);
	token_del(&factory->tokencontainer);
	ft_strcat(emsg, "'\n");
}
