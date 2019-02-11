/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:22:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 02:40:11 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				expand_tilde(t_cmdarg *arg, char **r_argv, t_shinfo *info)
{
	char *dummy;
	char *home;

	dummy = *r_argv;
	if (*dummy == '~' && (dummy[1] == '/' || !dummy[1]))
	{
		if ((home = info->home))
			copy_str2arg(arg, home, ft_strlen(home));
		dummy++;
	}
	*r_argv = dummy;
	return (arg->status);
}

static void		init_wexpinf(t_wexpinf *weinf, t_queue *argl, \
							t_cmdarg *arg, char *r_argv)
{
	ft_bzero(weinf, sizeof(*weinf));
	weinf->argline = arg;
	weinf->argl = argl;
	weinf->src = r_argv;
	weinf->src_orig = r_argv;
	weinf->state = 0;
	weinf->parsed_subst = 0;
	weinf->status = ST_CONTINUE;
}

static int		expand_aliases(t_queue *argv, t_varkey *aliases)
{
	char		*arg;
	char		*space;
	t_varkey	*vk;
	int			cmp;
	int			i;

	i = 0;
	while (42)
	{
		if (!(arg = ft_queue_lookat(argv, i))
		|| !(vk = aliases))
			return (FAILURE);
		while (vk && (cmp = ft_strcmp(arg, vk->key)) > 0)
			vk = vk->next;
		if (cmp)
			return (FAILURE);
		free(arg);
		arg = ft_strdup(vk->value);
		ft_queue_replaceat(argv, arg, i);
		if (!(space = ft_strrchr(arg, ' ')) || space[1] != '\0')
			break ;
		i++;
	}
	return (SUCCESS);
}

static int		parse_argv(t_queue *argl, t_cmdarg *arg, \
							char *r_argv, t_shdata *data)
{
	static int	(*exp_action[WEXP_ACOUNT])(t_wexpinf*, char*, t_shdata*) = { \
																WEXP_ACTIONS};
	t_wexpinf	weinf;
	char		*next_d;
	int			d_i;

	init_wexpinf(&weinf, argl, arg, r_argv);
	if (expand_tilde(arg, &weinf.src, &data->info) == FAILURE)
		return (FAILURE);
	while (weinf.status == ST_CONTINUE)
	{
		weinf.delim = get_delim_msk(weinf.state);
		next_d = chrmsk_getnext_match(weinf.src, weinf.delim);
		d_i = ft_chr2index(WEXP_ALLD, next_d ? *next_d : '\0');
		weinf.status = exp_action[d_i](&weinf, next_d, data);
	}
	if (weinf.src_orig != r_argv)
		free(weinf.src_orig);
	return (weinf.status);
}

int				fill_argv(t_cookedcmd *cmd, t_command *raw, t_shdata *data)
{
	static t_cmdarg		arg;
	char				*r_argv;
	int					argc;

	reset_arg(&arg);
	expand_aliases(raw->argv, data->aliases);
	argc = ft_queue_get_height(raw->argv);
	while (arg.status == SUCCESS && argc--)
	{
		r_argv = ft_queue_get(raw->argv);
		if (parse_argv(raw->argv, &arg, r_argv, data) == FAILURE
		|| add_arg_tolst(raw->argv, &arg) == FAILURE)
			arg.status = FAILURE;
		arg.size = 0;
		free(r_argv);
	}
	cmd->argc = ft_queue_get_height(raw->argv);
	return (arg.status);
}
