/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:40:44 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 14:04:59 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

static int	char_is_sign(char c, t_optdata *data)
{
	if (c == '-' && (data->signs & GETOPT_SNEG))
	{
		data->optsign = GETOPT_SNEG;
		return (SUCCESS);
	}
	if (c == '+' && (data->signs & GETOPT_SPOS))
	{
		data->optsign = GETOPT_SPOS;
		return (SUCCESS);
	}
	return (FAILURE);
}

static char	*get_optarg(t_optdata *data, int argc, char *const *argv)
{
	char		*curr_optarg;
	char		*optarg;
	int			ind;

	ind = data->optind;
	curr_optarg = data->optarg;
	if (!curr_optarg || !data->optopt || !*curr_optarg)
	{
		if (ind >= argc)
			return (NULL);
		optarg = argv[(data->optind++)];
	}
	else
		return (curr_optarg);
	if (char_is_sign(*optarg, data) == SUCCESS)
	{
		if ((data->optsign & GETOPT_SNEG) && ft_strequ(optarg, "--"))
			return (NULL);
		return (++optarg);
	}
	data->optind--;
	return (NULL);
}

static int	get_optopt(t_optdata *data, int argc, char *const *argv)
{
	int		ret;

	if (data->optopt == -1)
		return (-1);
	if (!(data->optarg = get_optarg(data, argc, argv)))
		return (-1);
	ret = *data->optarg;
	data->optarg++;
	return (ret);
}

void		init_optdata(t_optdata *data, int signs)
{
	data->optarg = NULL;
	data->optopt = 0;
	data->optind = 0;
	data->optsign = 0;
	data->signs = signs;
}

int			ft_getopt(t_optdata *data, int argc, \
					char *const *argv, const char *options)
{
	int			i;

	if ((data->optopt = get_optopt(data, argc, argv)) == -1)
		return (-1);
	i = -1;
	while (options[++i])
		if (data->optopt == options[i])
			return (options[i]);
	return ('?');
}
