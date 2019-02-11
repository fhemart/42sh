/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_exportline_tools.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 08:31:07 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/16 23:14:02 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ftsh.h"

int				count_previous_bs(char *line, int len)
{
	int			i;

	i = 0;
	while (len >= i && line[len - i] == '\\')
		i++;
	return (i);
}

char			*cancel_cmd(t_prompt *prompt)
{
	if (prompt->exit != -1)
		prompt->done = 0;
	return (NULL);
}

t_bool			treat_quotes(t_prompt *prompt)
{
	t_stack		*brstack;
	t_brinfo	*info;
	int			i;
	int			total;
	char		c;

	brstack = &prompt->brstack;
	total = (int)ft_stack_totalsize(brstack);
	i = -1;
	while (++i < total)
	{
		info = (t_brinfo*)ft_stack_lookat(brstack, i);
		c = *info->op;
		if (c == '`' || c == '\'' || c == '"')
			return (FALSE);
	}
	return (TRUE);
}

t_bool			all_quotes_closed(t_prompt *prompt, char *line)
{
	t_stack		*tmpstack;
	char		*tmpstr;
	t_bool		ret;
	t_brdata	*brdata;

	brdata = ((t_iuser*)prompt->cparam)->brdata;
	tmpstack = brdata->brstack;
	tmpstr = brdata->src;
	brdata->brstack = &prompt->brstack;
	brdata->src = line;
	ret = check_brackets(brdata);
	brdata->brstack = tmpstack;
	brdata->src = tmpstr;
	return (treat_quotes(prompt));
}
