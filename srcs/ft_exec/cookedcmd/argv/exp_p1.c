/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_p1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 02:47:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		exp_dvar(t_wexpinf *weinf, char *src, t_cmdarg *arg, t_shdata *data)
{
	char		*env_val;
	size_t		eklen;

	eklen = 1;
	while (is_valid_chr(src[eklen]))
		eklen++;
	env_val = sh_env_getvalue2(data->env, src, eklen);
	if (env_val && copy_str2arg(arg, env_val, ft_strlen(env_val)))
		return (ST_FAILURE);
	weinf->src = src + eklen;
	return (ST_CONTINUE);
}

int		exp_dargv(t_wexpinf *weinf, char *src, t_cmdarg *arg, t_shdata *data)
{
	int		ac;
	char	*av;

	ac = *src - '0';
	if (ac < data->argc)
	{
		av = data->argv[ac];
		if (copy_str2arg(arg, av, ft_strlen(av)) == FAILURE)
			return (ST_FAILURE);
	}
	weinf->src = ++src;
	return (ST_CONTINUE);
}

int		exp_dppc(t_wexpinf *weinf, char *src, t_cmdarg *arg, t_shdata *data)
{
	char	*ppcount;

	ppcount = ft_static_itoa(data->argc - 1);
	if (copy_str2arg(arg, ppcount, ft_strlen(ppcount)) == FAILURE)
		return (ST_FAILURE);
	weinf->src = ++src;
	return (ST_CONTINUE);
}

int		exp_dtargv(t_wexpinf *weinf, char *src, t_cmdarg *arg, t_shdata *data)
{
	int		i;
	int		ac;
	char	*av;

	ac = data->argc;
	i = 1;
	while (i < ac)
	{
		av = data->argv[i];
		if ((copy_str2arg(arg, av, ft_strlen(av)) == FAILURE)
		|| (++i != ac && copy_chr2arg(arg, ' ') == FAILURE))
			return (ST_FAILURE);
	}
	weinf->src = ++src;
	return (ST_CONTINUE);
}

int		exp_dlrv(t_wexpinf *weinf, char *src, t_cmdarg *arg, t_shdata *data)
{
	if (copy_int2arg(arg, data->last_retval) == FAILURE)
		return (ST_FAILURE);
	weinf->src = ++src;
	return (ST_CONTINUE);
}
