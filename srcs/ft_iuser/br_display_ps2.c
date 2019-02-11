/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   br_display_ps2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:36:27 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/17 02:23:25 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static void	print_qu_name(t_br_return *data, t_term *term)
{
	static char		*brname[SH_BRINFO_COUNT] = {SHBRINFNAMES};
	const t_brinfo	*binfo;
	t_prompt		*prompt;
	int				i;

	i = 0;
	binfo = ft_stack_lookat(data->opened_quotes, i);
	prompt = term->prompt;
	while (binfo)
	{
		if (binfo->type == BR_QUOTE)
			ft_strcpy(prompt->prompt, brname[binfo->index]);
		if ((binfo = ft_stack_lookat(data->opened_quotes, ++i)))
			ft_strcat(prompt->prompt, " ");
	}
}

char		*hist_get_entryat(t_histentry *entries, int pos)
{
	if (!entries)
		return (NULL);
	if (pos)
		return (hist_get_entryat(entries->prev, pos - 1));
	return (entries->string);
}

char		*hist_get_nentry(t_shhist *history, int n)
{
	int			pos;

	if (n < 0)
		pos = -(n + 1);
	else
		pos = -(n - history->entry_count);
	if (pos < 0)
		return (NULL);
	return (hist_get_entryat(history->entries, pos));
}

char		*br_display_ps2(t_br_return *data, t_iuser *iuser)
{
	char		*new_src;
	t_term		*term;
	t_shdata	*shdata;
	int			ret;

	shdata = iuser->shdata;
	term = shdata->term;
	ft_strdel(&iuser->src);
	if ((iuser->shdata->is_fork & IS_CMDSUBST))
		return (NULL);
	print_qu_name(data, term);
	ft_strcat(term->prompt->prompt, "> ");
	while ((ret = get_inputline(term, shdata, &new_src, 2)) > 0)
	{
		if (new_src && *new_src)
			return ((iuser->src = new_src));
		ft_strdel(&new_src);
	}
	if (ret == -1)
		iuser->tlex->errhead = NULL;
	return (NULL);
}
