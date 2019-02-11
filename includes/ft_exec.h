/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:59:21 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 02:47:21 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "errormsg.h"
# include "ftsh.h"
# include "ft_iuser.h"
# include "shell_env.h"

# include "libft.h"
# include "token_charsets/input_grammar_struct.h"

typedef struct s_cookedcmd	t_cookedcmd;
typedef struct s_cookedio	t_cookedio;
typedef struct s_fdlist		t_fdlist;
typedef struct s_wexpinf	t_wexpinf;
typedef struct s_cmdarg		t_cmdarg;
typedef struct s_shinfo		t_shinfo;
typedef struct s_shdata		t_shdata;

# define FT_EXC_BUILTIN		0
# define FT_EXC_FILE		(1 << 8)

struct		s_cmdarg
{
	char	buff[_POSIX_ARG_MAX + 1];
	ssize_t	size;
	int		status;
};

struct		s_fdlist
{
	t_fdlist	*next;
	int			fd;
};

struct		s_cookedio
{
	t_fdlist	*openedfd;
	int			stdio[3];
	t_bool		modified;
};

struct		s_cookedcmd
{
	int			type;
	t_cookedio	cookedio;
	t_iocontent	*ioctt;
	char		*name;
	char		**argv;
	t_sh_evar	*env_var;
	char		**env;
	int			argc;
};

char		**create_tmpenv(t_cookedcmd *cmd);

int			get_command(t_shdata *shdata);

int			ft_exec_inputlist(t_queue **cmdq, t_shdata *shdata);
int			ft_exec_andor(t_queue *aoqueue, t_shdata *shdata);
int			ft_exec_pipeline(t_command *pipeline, t_shdata *shdata);
int			exec_piped_cmd(t_command *pipeline, t_shdata *shdata);
int			ft_exec_cmd(t_command *cmd_raw, t_shdata *shdata);
int			ft_exec_cookedcmd(t_cookedcmd *cmd, t_shdata *shdata);
void		ft_exec_shellfile(t_cookedcmd *cmd, t_shdata *shdata);

int			parse_exec_ret(int value, t_cookedcmd *cmd, pid_t pid);

int			pl_exec_cmd(t_command *cmd_raw, t_shdata *shdata);
int			pl_exec_cookedcmd(t_cookedcmd *cmd, t_shdata *shdata);
int			pl_exec_file(t_cookedcmd *cmd, t_shdata *shdata);
int			exec_subshell(t_subshell *subshell, t_shdata *shdata);
int			pl_exec_builtin(t_cookedcmd *cmd, t_shdata *shdata);

int			compress_iocontent(t_cookedio *cookedio, t_iocontent *ioctt);
t_cookedcmd	*cookedcmd_new(t_command *raw, t_shdata *shdata);
int			get_cmdtype(t_cookedcmd *cmd, t_shdata *data, char *errhead);
char		*get_command_name(t_cookedcmd *cmd, t_shdata *data, char *errhead);
void		init_stdiotable(int *stdio);
void		cookedcmd_del(t_cookedcmd **cmd);
void		reset_cookedio(t_cookedio *cdio);

t_fdlist	*update_fdlist(t_fdlist **fdlhead, int newfd, int oldfd);
int			get_rh_from_fd(char *str, int *close_fd);
int			get_rh_from_file1(char *str, int *close_fd);
int			get_rh_from_file2(char *str, int *close_fd);
int			get_rh_from_file3(char *str, int *close_fd);
int			get_rh_from_fd(char *str, int *close_fd);
void		update_stdtable(int *stdio, int fdold, int fdnew);
int			call_dup2(int fdlh, int fdrh);
int			iof_heredoc(int fd_left, char *str, t_cookedio *cookedio);
int			iof_dgreat(int fd_left, char *str, t_cookedio *cookedio);
int			iof_lgand(int fd_left, char *str, t_cookedio *cookedio);
int			iof_great(int fd_left, char *str, t_cookedio *cookedio);
int			iof_sand(int fd_left, char *str, t_cookedio *cookedio);
int			iof_less(int fd_left, char *str, t_cookedio *cookedio);
void		protected_close(int fd);

char		*get_command_name(t_cookedcmd *cmd, t_shdata *data, char *errhead);
int			fill_argv(t_cookedcmd *cmd, t_command *raw, t_shdata *data);

void		reset_arg(t_cmdarg *arg);
int			copy_chr2arg(t_cmdarg *arg, char c);
int			copy_int2arg(t_cmdarg *arg, int i);
int			copy_str2arg(t_cmdarg *arg, char *str, size_t n);
int			add_arg_tolst(t_queue *argl, t_cmdarg *arg);

int			expand_tilde(t_cmdarg *arg, char **r_argv, t_shinfo *info);

int			exp_dvar(t_wexpinf *wi, char *src, t_cmdarg *arg, t_shdata *data);
int			exp_dargv(t_wexpinf *wi, char *src, t_cmdarg *arg, t_shdata *data);
int			exp_dppc(t_wexpinf *wi, char *src, t_cmdarg *arg, t_shdata *data);
int			exp_dtargv(t_wexpinf *wi, char *src, t_cmdarg *arg, t_shdata *data);
int			exp_dlrv(t_wexpinf *wi, char *src, t_cmdarg *arg, t_shdata *data);
int			exp_dolq(t_wexpinf *wi, char *src, t_cmdarg *arg, t_shdata *data);
int			exp_dshpid(t_wexpinf *wi, char *src, t_cmdarg *arg, t_shdata *data);
int			exp_dnone(t_wexpinf *wi, char *src, t_cmdarg *arg, t_shdata *data);
int			exp_dolcmd(t_wexpinf *wi, char *src, t_cmdarg *arg, t_shdata *data);

int			exp_qu(t_wexpinf *weinf, char *next_d, t_shdata *data);
int			exp_dqu(t_wexpinf *weinf, char *next_d, t_shdata *data);
int			exp_end(t_wexpinf *weinf, char *next_d, t_shdata *data);
int			exp_dollar(t_wexpinf *weinf, char *next_d, t_shdata *data);
int			exp_equal(t_wexpinf *weinf, char *next_d, t_shdata *data);
int			exp_bs(t_wexpinf *weinf, char *next_d, t_shdata *data);
int			exp_space(t_wexpinf *weinf, char *next_d, t_shdata *data);
int			exp_btick(t_wexpinf *weinf, char *src, t_shdata *data);
int			exp_space(t_wexpinf *weinf, char *next_d, t_shdata *data);

char		parse_bsoct(char *bs, char **src);
char		parse_bshex(char *bs, char **src);
char		parse_bsctrl(char *bs, char **src);
char		parse_backslash_total(char *bs, char **src);

t_iuser		*get_cmdsubst_iuser(char *src, t_shdata *data);
int			parse_cmd(t_iuser *iuser, t_shdata *data, char *errhead);
char		*get_child_stdout(int read_fd, pid_t child, t_shdata *data);
void		proceed_child_cmdsubst(char *curr_param, char *src, t_shdata *data);
int			proceed_parent_cmdsubst(t_wexpinf *wi, char *src, t_shdata *data);

void		print_sh_parse_error(t_shdata *data, char *errhead);

t_chrmsk	*get_delim_msk(int index);

# define WEXP_ALLMSK		0
# define WEXP_ALLD			"$=\\'\" \t\n`"

# define WEXP_DOQMSK		2
# define WEXP_DOQSTR		"\\'"

# define WEXP_BSMSK			3
# define WEXP_BSSTRM		"bfnrtv\\'\""
# define WEXP_BSEQM			"\b\f\n\r\t\v\\'\""

# define WEXP_DQUBSMSK		4
# define WEXP_DQUBSSTR		"$\"\\"

# define WEXP_DODQMSK		5
# define WEXP_DODQSTR		"\\'\""

# define WEXP_DOLLARMSK		6
# define WEXP_DOLLARSTR		"#@?$'("

# define WEXP_BQUMSK		7
# define WEXP_BQUSTR		"\\ \t\n"

# define WEXP_DQUBQUMSK		8
# define WEXP_DQUBQUSTR		"\\"

# define WEXP_SPMSKOFFSET		WEXP_DQUMSK - 1

# define WEXP_DQUMSK		9
# define WEXP_DQUSTR		"$\\\"`"

# define WEXP_CMDSUBSTMSK	10
# define WEXP_CMDSUBSTSTR	" \t\n"

# define WEXP_DQUCMDMSK		11
# define WEXP_DQUCMDSTR		""

# define WEXP_DCOUNT	12
# define WEXP_DSTR1		WEXP_ALLD, "$\\'\"", WEXP_DOQSTR, WEXP_BSSTRM
# define WEXP_DSTR2		WEXP_DQUBSSTR, WEXP_DODQSTR, WEXP_DOLLARSTR
# define WEXP_DSTR3		WEXP_BQUSTR, WEXP_DQUBQUSTR
# define WEXP_DSPSTR	WEXP_DQUSTR, WEXP_CMDSUBSTSTR, WEXP_DQUCMDSTR
# define WEXP_DSTR		WEXP_DSTR1, WEXP_DSTR2, WEXP_DSTR3, WEXP_DSPSTR

# define SET_DQUMODE	(1 << 8)
# define SET_CMDSUBMODE	(1 << 9)

# define WEXP_ALLDLEN	9
# define WEXP_ACOUNT	WEXP_ALLDLEN + 1
# define WEXP_ACTIONS	WEXP_ACTIONSP1, WEXP_ACTIONSP2, exp_end
# define WEXP_ACTIONSP1	exp_dollar, exp_equal, exp_bs, exp_qu, exp_dqu
# define WEXP_ACTIONSP2	exp_space, exp_space, exp_space, exp_btick

# define WEXP_DFCOUNT	6
# define WEXP_DOLLARF1	exp_dppc, exp_dtargv, exp_dlrv, exp_dshpid
# define WEXP_DOLLARF2	exp_dolq, exp_dolcmd
# define WEXP_DOLLARF	WEXP_DOLLARF1, WEXP_DOLLARF2

struct		s_wexpinf
{
	t_cmdarg	*argline;
	t_queue		*argl;
	t_chrmsk	*delim;
	char		*src;
	char		*save_src;
	char		*src_cmdsubst;
	char		*src_orig;
	int			save_state;
	int			state;
	int			status;
	int			parsed_subst;
};

#endif
