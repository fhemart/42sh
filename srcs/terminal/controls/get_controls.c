/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 04:37:43 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/27 14:54:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

t_control		*get_emacs_controls(void)
{
	static long			key_handle[NBKEYS_EMACS] = {KEYS_EMACS};
	static int			(*f[NBKEYS_EMACS])(t_prompt*, t_term*) = {FN_EMACS};
	static t_control	ret;

	if (!ret.key_handle)
	{
		ret.nbaction = NBKEYS_EMACS;
		ret.key_handle = key_handle;
		ret.f = f;
	}
	return (&ret);
}

t_control		*get_std_controls(void)
{
	static long			key_handle[NBKEYS_STD] = {KEYS_STD};
	static int			(*f[NBKEYS_STD])(t_prompt*, t_term*) = {FN_STD};
	static t_control	ret;

	if (!ret.key_handle)
	{
		ret.nbaction = NBKEYS_STD;
		ret.key_handle = key_handle;
		ret.f = f;
	}
	return (&ret);
}
