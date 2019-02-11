/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:35:59 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:26:16 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# include "libft.h"

typedef struct s_optdata	t_optdata;
typedef struct s_argpack	t_argpack;

# define GETOPT_SNEG	(1 << 0)
# define GETOPT_SPOS	(1 << 1)
# define GETOPT_SBOTH	(GETOPT_SNEG | GETOPT_SPOS)

struct	s_optdata
{
	char	*optarg;
	int		optopt;
	int		optind;
	int		optret;
	int		optsign;
	int		signs;
};

struct	s_argpack
{
	char	**argv;
	int		argc;
};

void	init_optdata(t_optdata *data, int signs);
int		ft_getopt(t_optdata *data, int argc, \
				char *const *argv, const char *options);

typedef struct s_checkopt_inf	t_checkopt_inf;

struct	s_checkopt_inf
{
	int		(*optaction)(t_optdata*, t_checkopt_inf*);
	char	*msk;
	void	*custom;
	int		flags;
};

void	init_coptinf(t_checkopt_inf *dst, char *msk, void *custom, \
					int (*optaction)(t_optdata*, t_checkopt_inf*));
int		check_opt(int argc, char **args, int signs, t_checkopt_inf *optinf);
#endif
