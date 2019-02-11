/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_evar_print_debug.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:55:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/07 13:23:51 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_env.h"
#include "ft_strings.h"

static size_t	get_max_keylen(t_sh_evar *varlist)
{
	size_t	max;
	size_t	len;

	max = 0;
	while (varlist)
	{
		if ((len = ft_strlen(varlist->key)) > max)
			max = len;
		varlist = varlist->next;
	}
	return (max);
}

static size_t	get_max_valuelen(t_sh_evar *varlist)
{
	size_t	max;
	size_t	len;

	max = 0;
	while (varlist && max < 80)
	{
		if ((len = ft_strlen(varlist->value)) > max)
			max = len;
		varlist = varlist->next;
	}
	return (max > 80 ? 80 : max);
}

static void		add_evar_debughead(t_awstr *awstr, t_awpad keys, t_awpad values)
{
	keys.c = '*';
	values.c = '*';
	ft_awstrncat(awstr, "**", 2);
	ft_awstrrpad(awstr, "", 0, keys);
	ft_awstrncat(awstr, "***", 3);
	ft_awstrrpad(awstr, "", 0, values);
	ft_awstrncat(awstr, "**\n", 3);
}

static void		sh_evar_print_one(t_sh_evar *var, t_awstr *awstr, \
								t_awpad keys, t_awpad values)
{
	size_t	vlen;
	char	*value;

	if (!var)
		return ;
	sh_evar_print_one(var->next, awstr, keys, values);
	ft_awstrncat(awstr, "* ", 2);
	ft_awstrrpad(awstr, var->key, ft_strlen(var->key), keys);
	ft_awstrncat(awstr, " * ", 3);
	value = var->value;
	vlen = ft_strlen(var->value);
	while (vlen > values.height)
	{
		ft_awstrrpad(awstr, value, values.height, values);
		ft_awstrncat(awstr, " *\n", 3);
		ft_awstrncat(awstr, "* ", 2);
		ft_awstrrpad(awstr, " |-", 3, keys);
		ft_awstrncat(awstr, " * ", 3);
		value += values.height;
		vlen -= values.height;
	}
	ft_awstrrpad(awstr, value, vlen, values);
	ft_awstrncat(awstr, " *\n", 3);
}

void			sh_evar_print_debug(t_sh_evar *varlist)
{
	t_awstr		awstr;
	t_awpad		keys;
	t_awpad		values;

	awstr.size = 0;
	keys = ft_awpad(' ', get_max_keylen(varlist));
	values = ft_awpad(' ', get_max_valuelen(varlist));
	add_evar_debughead(&awstr, keys, values);
	sh_evar_print_one(varlist, &awstr, keys, values);
	add_evar_debughead(&awstr, keys, values);
	ft_putawstr(&awstr);
}
