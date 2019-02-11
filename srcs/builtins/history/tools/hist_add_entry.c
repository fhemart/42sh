/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_add_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 18:50:27 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			hist_add_entry(t_shhist *history, char *str)
{
	t_histentry		*new;

	if (!(new = hist_new_entry(str)))
		return (FAILURE);
	hist_ins_entry(&history->entries, new);
	history->entry_count++;
	return (SUCCESS);
}
