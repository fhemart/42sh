/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_io_here.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 19:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/26 17:48:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftsh.h"
#include "token_charsets/input_grammar_struct.h"
#include "ft_tlex.h"

static char		*print_heredoc_error(char *here_end, int inputline, char *ret, \
							t_tlexicon *lex)
{
	if (inputline == -1)
	{
		ft_strdel(&ret);
	}
	lex->errhead = NULL;
	ft_strdel(&here_end);
	return (ret);
}

static void		modify_gnl(char *gnl, int state)
{
	size_t	len;
	char	*tabi;

	if (state != 0)
	{
		tabi = gnl;
		while (*tabi == '\t')
			tabi++;
		if (tabi != gnl)
			ft_strcpy(gnl, tabi);
	}
	len = ft_strlen(gnl);
	if (len > 1 && gnl[len - 2] == '\\')
		*(short*)(gnl + (len - 2)) = *(short*)"\n";
}

char			*get_here_doc(t_tlexicon *lex, t_iuser *iuser, \
								char *herend, int state)
{
	size_t		len;
	char		*str[2];
	int			iline;
	t_term		*term;
	t_shdata	*shdata;

	shdata = iuser->shdata;
	term = shdata->term;
	str[0] = NULL;
	while (42)
	{
		ft_strcpy(term->prompt->prompt, "heredoc> ");
		if ((iline = get_inputline(term, shdata, &str[1], 4)) <= 0)
			return (print_heredoc_error(herend, iline, str[0], lex));
		len = ft_strlen(str[1]) - 1;
		if (len == ft_strlen(herend) && ft_strnequ(str[1], herend, len))
			break ;
		modify_gnl(str[1], state);
		str[0] = ft_strjoin_proper(&str[0], str[1]);
		free(str[1]);
	}
	free(str[1]);
	free(herend);
	return (str[0]);
}

void			*reduce_io_here(t_tkn_factory *tfactory, t_exptoken *expr)
{
	t_iocontent	*io_here;
	t_exptoken	*here_end;
	t_token		*type;
	char		*str;

	io_here = NULL;
	here_end = ft_zebu_get_curr_tok(tfactory);
	type = ft_zebu_get_curr_tok(tfactory);
	token_del(&type);
	if (!(str = get_here_doc(tfactory->lex, tfactory->customparam, \
							here_end->reduced, expr->validstate))
	|| !(io_here = new_iocontent(str, HEREDOCOFFSET + expr->validstate)))
		tfactory->main_status = TF_STATUS_ERROR;
	token_del((t_token**)&here_end);
	return (io_here);
}
