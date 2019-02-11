/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_p4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:58:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/02 15:43:22 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			exp_dollar(t_wexpinf *weinf, char *next_d, t_shdata *data)
{
	static int	(*f[WEXP_DFCOUNT])(t_wexpinf*, char*, t_cmdarg*, t_shdata*) = {\
																WEXP_DOLLARF};
	t_cmdarg	*arg;
	char		*src;
	char		c;

	src = weinf->src;
	arg = weinf->argline;
	if (copy_str2arg(arg, src, next_d - src) == FAILURE)
		return (ST_FAILURE);
	src = next_d + 1;
	if (is_valid_firstchr((c = *src)))
		return (exp_dvar(weinf, src, arg, data));
	else if (ft_isdigit(c))
		return (exp_dargv(weinf, src, arg, data));
	else if (char_match_pattern(c, get_delim_msk(WEXP_DOLLARMSK)))
		return (f[ft_chr2index(WEXP_DOLLARSTR, c)](weinf, src, arg, data));
	return (exp_dnone(weinf, src, arg, data));
}

int			exp_space(t_wexpinf *weinf, char *next_d, t_shdata *data)
{
	t_cmdarg	*arg;
	char		*src;

	(void)data;
	arg = weinf->argline;
	src = weinf->src;
	if (copy_str2arg(arg, src, next_d - src) == FAILURE
	|| add_arg_tolst(weinf->argl, arg) == FAILURE)
		return (ST_FAILURE);
	weinf->src = next_d + 1;
	return (ST_CONTINUE);
}

int			exp_btick(t_wexpinf *weinf, char *src, t_shdata *data)
{
	int		pfd[2];
	pid_t	pid;

	if (pipe(pfd) == -1)
		return (ST_FAILURE);
	else if ((pid = fork()) == -1)
	{
		close(pfd[0]);
		close(pfd[1]);
		p_eagain(SHELL_NAME ": fork: ");
		return (ST_FAILURE);
	}
	else if (pid == 0)
	{
		close(pfd[0]);
		call_dup2(pfd[1], STDOUT_FILENO);
		proceed_child_cmdsubst(weinf->src_orig, src, data);
	}
	close(pfd[1]);
	if (!(weinf->src_cmdsubst = get_child_stdout(pfd[0], pid, data)))
		return (ST_FAILURE);
	return (proceed_parent_cmdsubst(weinf, src, data));
}

int			exp_dolcmd(t_wexpinf *weinf, char *src, t_cmdarg *arg, \
						t_shdata *data)
{
	int		ret;

	(void)arg;
	ret = exp_btick(weinf, src, data);
	weinf->state += (WEXP_CMDSUBSTMSK - WEXP_BQUMSK);
	return (ret);
}
