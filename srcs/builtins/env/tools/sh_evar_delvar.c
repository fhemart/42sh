/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_evar_delvar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/14 10:39:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

static void		del_head(t_sh_evar **varlist)
{
	t_sh_evar	*next;

	if (!*varlist)
		return ;
	next = (*varlist)->next;
	sh_evar_delone(varlist);
	*varlist = next;
}

void			sh_evar_delvar(t_sh_evar **varlist, t_sh_evar *var)
{
	t_sh_evar	*prev;
	t_sh_evar	*dummy;
	t_sh_evar	*next;

	if ((dummy = *varlist) == var)
		return (del_head(varlist));
	prev = NULL;
	while (dummy && dummy != var)
	{
		prev = dummy;
		dummy = dummy->next;
	}
	next = dummy ? dummy->next : NULL;
	sh_evar_delone(&var);
	if (prev)
		prev->next = next;
}
