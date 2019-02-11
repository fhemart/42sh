/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iuser_tlex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:36:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 22:51:01 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static void	try_convert_ionum(t_token *tok)
{
	int		value;

	if ((value = ft_atoi(tok->content)) >= IUSER_MAX_IOFD)
		return ;
	tok->type = TIONUMBER;
	tok->content_size = value;
	ft_strdel(&tok->content);
}

static int	word_checker(t_tlexicon *tlex, t_token *tok, t_iuser *iuser)
{
	(void)iuser;
	if (tok->content_size <= 4 && ft_strisdigit(tok->content)
	&& (*tlex->src == '>' || *tlex->src == '<'))
		try_convert_ionum(tok);
	return (0);
}

t_tlexicon	*get_iuser_tlex(t_iuser *iuser, int gsd)
{
	static t_tlexicon	*tlex = NULL;
	static char			errhead[] = SHELL_NAME": ";

	if (gsd == FT_STGET)
	{
		if (!tlex)
		{
			if (!(tlex = ft_tlex_new(NULL, TRUE, get_iuser_grammar(FT_STGET)))
			|| ft_tlex_addwpolish((int(*)())word_checker, iuser, tlex) == -1)
				ft_tlex_destroy(&tlex);
			else
				tlex->errhead = errhead;
		}
	}
	else if (gsd == FT_STSET && tlex)
		tlex->errhead = errhead;
	else if (gsd == FT_STDEL)
		ft_tlex_destroy(&tlex);
	return (tlex);
}
