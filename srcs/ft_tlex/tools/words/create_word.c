/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 02:06:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/07 10:44:03 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tlex.h"

t_token	*create_word(t_tlexicon *tlex)
{
	t_lstr			*str;
	char			*content;
	int				size;
	t_token			*new;

	if (!(str = get_wordcontent(tlex, tlex->grammar)))
	{
		tlex->main_status = TF_STATUS_ERROR;
		return (NULL);
	}
	content = ft_lstr_tostring(str);
	size = ft_lstrlen(str);
	ft_lstrdel(&str);
	new = create_new_token(content, size, ft_tlex_gword(tlex));
	if (!new)
		tlex->main_status = TF_STATUS_ERROR;
	return (new);
}
