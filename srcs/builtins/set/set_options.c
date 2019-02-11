/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:45:12 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/15 18:16:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"

static int	increase_optarg(t_optdata *opt_data, t_argpack *pack)
{
	if (opt_data->optind >= pack->argc)
		return (FAILURE);
	opt_data->optarg = pack->argv[opt_data->optind++];
	return (SUCCESS);
}

static char	*get_next_arg(t_optdata *opt_data, t_argpack *pack)
{
	char	c;

	if ((c = *opt_data->optarg) == '=')
		opt_data->optarg += 1;
	while (!*opt_data->optarg)
	{
		if (increase_optarg(opt_data, pack) == FAILURE)
			return (NULL);
	}
	return (opt_data->optarg);
}

static void	update_flags(t_checkopt_inf *info, int optsign, int shift)
{
	int		s;

	s = (1 << shift) << 8;
	if (optsign == GETOPT_SNEG)
		info->flags = ((info->flags & ~s) | (1 << shift));
	else
		info->flags = ((info->flags & ~(1 << shift)) | s);
}

static int	update_verbopt(t_optdata *opt_data, t_checkopt_inf *info)
{
	static char		*optname[SET_VERBO_CNT] = {SET_VERBO_STR};
	int				shift;
	char			*cmp;

	if (!(cmp = get_next_arg(opt_data, info->custom)))
	{
		info->flags |= SET_PRINTOPT;
		return (ST_SUCCESS);
	}
	shift = 0;
	while (shift < SET_VERBO_CNT && ft_strequ(cmp, optname[shift]) == FALSE)
		shift++;
	if (shift < SET_VERBO_CNT)
	{
		if (shift >= SET_VERBO_OS)
			shift += SET_OPT_OS;
		update_flags(info, opt_data->optsign, shift);
		opt_data->optarg += ft_strlen(opt_data->optarg);
	}
	return (ST_CONTINUE);
}

int			set_optaction(t_optdata *opt_data, t_checkopt_inf *info)
{
	char	c;
	int		shift;

	if ((c = opt_data->optret) == '?')
		return (ST_CONTINUE);
	if (c == 'o')
		return (update_verbopt(opt_data, info));
	shift = ft_chr2index(info->msk, opt_data->optret);
	update_flags(info, opt_data->optsign, shift);
	return (ST_CONTINUE);
}
