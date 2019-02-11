/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_evar_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/07/14 11:29:43 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"

void			sh_evar_delone(t_sh_evar **var)
{
	t_sh_evar	*dummy;

	if (!(dummy = *var))
		return ;
	ft_strdel(&dummy->key);
	ft_strdel(&dummy->value);
	free(dummy);
	*var = NULL;
}
