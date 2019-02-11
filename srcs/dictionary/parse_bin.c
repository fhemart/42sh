/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:31:44 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/09 02:11:57 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "books.h"

int		parse_htbin(t_hashtable *hashtable, t_list *binpath)
{
	if (!binpath)
		return (SUCCESS);
	ft_browse_dir(binpath->content, ft_hashtable_addcontent, hashtable, \
		hashtable_new_content);
	return (parse_htbin(hashtable, binpath->next));
}

int		parse_bin(t_dictionary *bin, t_hashtable *hashtable, t_list *binpath)
{
	if (!bin || !binpath)
		return (SUCCESS);
	ft_browse_dir(binpath->content, ft_dictionary_addword, bin, NULL);
	ft_browse_dir(binpath->content, ft_hashtable_addcontent, hashtable, \
		hashtable_new_content);
	return (parse_bin(bin, hashtable, binpath->next));
}
