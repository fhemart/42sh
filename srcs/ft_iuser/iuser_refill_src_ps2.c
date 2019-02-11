/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iuser_refill_src_ps2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 04:17:06 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/17 14:25:42 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static char		*get_tokstr(int *tok)
{
	const int	tok_type[4] = {TLPAR, TAND_IF, TOR_IF, TPIPE};
	static char	*tok_str[5] = {"subsh", "cmdand", "cmdor", "pipe", "??"};
	int			type;
	int			i;

	type = *tok;
	i = 0;
	while (i < 4 && type != tok_type[i])
		i++;
	return (tok_str[i]);
}

static t_bool	copy_str_tops2(char **ps2, size_t *ps2_size, char *tocpy)
{
	char		*tmp;
	size_t		slen;

	slen = ft_strlen(tocpy);
	tmp = *ps2;
	if ((*ps2_size += slen) >= 250)
	{
		ft_strcpy(tmp, "...");
		*ps2 += 3;
		return (FALSE);
	}
	ft_strcpy(tmp, tocpy);
	*ps2 += slen;
	return (TRUE);
}

static void		prepare_ps2(char *ps2, t_queue *op_expr)
{
	size_t		ps2_size;
	char		*tostr;
	int			qsize;
	int			i;

	ps2_size = 0;
	qsize = ft_queue_get_height(op_expr);
	i = -1;
	while (++i < qsize)
	{
		tostr = get_tokstr(ft_queue_lookat(op_expr, i));
		if (*tostr == '?')
			continue ;
		if (i != 0)
		{
			ft_strcpy(ps2++, " ");
			ps2_size++;
		}
		if (copy_str_tops2(&ps2, &ps2_size, tostr) == FALSE)
			break ;
	}
	ft_strcpy(ps2, "> ");
}

t_bool			iuser_refill_src_ps2(t_iuser *iuser, int last_type)
{
	char		ps2[256];
	char		**srcaddr;
	t_term		*term;
	t_shdata	*shdata;
	int			ret;

	(void)last_type;
	srcaddr = &iuser->src;
	shdata = iuser->shdata;
	term = shdata->term;
	ft_strdel(srcaddr);
	prepare_ps2(ps2, iuser->op_expr);
	ft_strcpy(term->prompt->prompt, ps2);
	while ((ret = get_inputline(term, shdata, srcaddr, 3)) > 0)
	{
		if (iuser->src && *iuser->src)
			return (TRUE);
		ft_strdel(srcaddr);
		ft_strcpy(term->prompt->prompt, ps2);
	}
	if (ret == -1)
		iuser->tlex->errhead = NULL;
	return (FALSE);
}
