/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_exportline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:13:20 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/17 03:28:40 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_prompt_private.h"
#include "ftsh.h"

static void		add_new_strlink(t_line *root, t_prompt *prompt)
{
	t_list		*new_sl;
	char		*str;
	size_t		slen;

	slen = root->nbelem + 1;
	if (!(new_sl = ft_memalloc(sizeof(*new_sl)))
	|| !(str = ft_dlist2str(root)))
		return (ft_memdel((void**)&new_sl));
	new_sl->content_size = slen;
	new_sl->content = str;
	ft_lstadd(&prompt->str_line, new_sl);
	prompt->sline_iter++;
}

static void		compress_line(t_prompt *prompt, char *line)
{
	t_list		*dummy;
	size_t		len;

	while (prompt->sline_iter > 1)
	{
		dummy = prompt->str_line;
		prompt->str_line = dummy->next;
		ft_lstdelone(&dummy, ft_memdel);
		prompt->sline_iter--;
	}
	if (prompt->ps == 4)
		return ;
	dummy = prompt->str_line;
	ft_memdel(&dummy->content);
	len = ft_strlen(line) + 1;
	if (!(dummy->content = ft_memdup(line, len)))
		return ;
	dummy->content_size = len;
	prompt->sline_iter = 0;
}

static char		*export_ps4(t_line *root, t_prompt *prompt)
{
	char	*str;

	if (prompt->exit == -1)
		return (cancel_cmd(prompt));
	str = ft_dlist2str(root);
	return (str);
}

static void		set_prompt_quote(t_prompt *prompt)
{
	if (prompt->ps == 1)
		ft_strcpy(prompt->prompt, "> ");
	prompt->promptlen = 3;
	prompt->done = 0;
	prompt->str_line->content_size -= 2;
}

char			*ft_prompt_exportline(t_line *root, t_prompt *prompt)
{
	char		*line;
	size_t		slen;

	if (prompt->ps == 4)
		return (export_ps4(root, prompt));
	if (root->nbelem == 1 && !ft_stack_totalsize(&prompt->brstack)
	&& !prompt->sline_iter)
		return (cancel_cmd(prompt));
	line = NULL;
	add_new_strlink(root, prompt);
	line = prompt->str_line->content;
	slen = prompt->str_line->content_size;
	if ((count_previous_bs(line, slen - 3) % 2)
	&& all_quotes_closed(prompt, line))
	{
		line[slen - 3] = '\0';
		set_prompt_quote(prompt);
		return (NULL);
	}
	line = ft_nlst2str(prompt->str_line, prompt->sline_iter);
	compress_line(prompt, line);
	return (line);
}
