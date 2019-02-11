/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:00:50 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/09 20:01:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_PRIVATE_H
# define BUILTINS_PRIVATE_H

# include <sys/stat.h>
# include <limits.h>
# include "builtins.h"
# include "ft_getopt.h"
# include "ftsh.h"

t_bool		builtin_need_help(char **argv);

/*
**		BUILTIN : ENV
*/

# define BI_1N	"env"
# define BI_1F	builtin_env
# define ENV_PRINT		0
# define ENV_ERROR		1
# define ENV_EXEC		2
# define ENV_ERR_DZERO	"env: cannot specify -0 with command"
# define ENV_USAGE		"Try 'env --help' for more information."

# define ENV_HELP		ENV_HELP_P1"\n"ENV_HELP_P2"\n"ENV_HELP_P3
# define ENV_HELP_P1	ENV_H1"\n"ENV_H2"\n"
# define ENV_HELP_P2	ENV_H3"\n"ENV_H4"\n"ENV_H6"\n"
# define ENV_HELP_P3	ENV_H7"\n"
# define ENV_H1 "Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]"
# define ENV_H2 "Set each NAME to VALUE in the environment and run COMMAND."

# define ENV_H3 "  -i       start with an empty environment"
# define ENV_H4 "  -0       end each output line with NUL, not newline"
# define ENV_H6 "  --help   display this help and exit"

# define ENV_H7		ENV_H7_P1 ENV_H7_P2
# define ENV_H7_P1 "A mere - implies -i."
# define ENV_H7_P2 "  If no COMMAND, print the resulting environment."

typedef struct s_setenvsave		t_setenvsave;

int			builtin_env(t_cookedcmd *cmd, t_shdata *shdata);
int			env_optaction(t_optdata *opt_data, t_checkopt_inf *info);
int			exec_env(t_envsave *sve, t_cookedcmd *cmd, int opt, t_shdata *data);
t_sh_evar	*env_parse_argv(t_cookedcmd *cmd, int opt_env, int *status);
int			env_print(t_sh_evar *var, char endl);
void		check_env_info_update(t_setenvsave *save, t_shdata *data);
void		get_env_info(t_setenvsave *save, t_shdata *data);

/*
**		BUILTIN : SETENV
*/

# define BI_2N	"setenv"
# define BI_2F	builtin_setenv
# define SETENV_USAGE	BI_2N": usage: setenv [-p] [name[=value] ...]"
# define SETENV_ENVID	": not a valid identifier"

int			builtin_setenv(t_cookedcmd *cmd, t_shdata *shdata);
void		setenv_envid(char *name);
void		parse_tilde(char **src, t_sh_env *env);

# define BI_3N	"unsetenv"
# define BI_3F	builtin_unsetenv
# define UNSETENV_USAGE	BI_3N": usage: unsetenv [name ...]"
# define UNSETENV_IDDNE	": identifier doesn't exist"

int			builtin_unsetenv(t_cookedcmd *cmd, t_shdata *shdata);
void		unsetenv_id_doesntexist(char *name);

/*
**		BUILTIN : CD
*/

# define BI_4N	"cd"
# define BI_4F	builtin_cd
# define CD_USAGE	BI_4N": usage: cd [-] [dir]"
# define CD_VAR_NOT_SET(x)	SHELL_NAME": cd: "x" not set"
# define CD_EHOME	CD_VAR_NOT_SET("HOME")
# define CD_EOPWD	CD_VAR_NOT_SET("OLDPWD")

int			builtin_cd(t_cookedcmd *cmd, t_shdata *shdata);

t_list		*next_valid_folder(t_list *folders);
int			cd_go_home(int flags, t_shdata *shdata);
int			cd_go_oldpwd(int flags, t_shdata *shdata);
int			access_folder(int flags, char *arg, char *pwd, t_shdata *shdata);
int			find_path(int flags, char *arg, t_shdata *shdata);
int			parse_file_lnk(char *buff, char *arg, char *pwd);
int			parse_file_physx(char *buff, char *arg, char *pwd);
int			parse_dots(char *path, t_bool lookbefore);
int			follow_links(char *buff, size_t curr_len, char *tofollow);
t_bool		is_dotdot(char *path);
int			is_directory(char *dir);
t_list		*next_valid_folder(t_list *folders);
char		*list_to_path(char *path, t_list *folders);
t_list		*remove_dot(t_list *folders);

/*
**		BUILTIN : ECHO
*/

# define BI_5N	"echo"
# define BI_5F	builtin_echo

int			builtin_echo(t_cookedcmd *cmd, t_shdata *shdata);

int			print_param(char **args);
int			print_param_bs(char **args);
char		*parse_bs(char *last, char *curr, t_awstr *awstr, int *cut);
char		parse_bshex(char *bs, char **src);
char		parse_bsoct(char *bs, char **src);
int			bs_act_hex(t_awstr *awstr, char **src, int *cut);
int			is_escape_sequence(char c);

/*
**		BUILTIN : EXIT
*/

# define BI_6N	"exit"
# define BI_6F	builtin_exit

int			builtin_exit(t_cookedcmd *cmd, t_shdata *shdata);

/*
**		BUILTIN : ALIAS
*/

# define BI_7N	"alias"
# define BI_7F	builtin_alias
# define ALIAS_USAGE	BI_7N": usage: alias [-p] [name[=value] ... ]"

int			builtin_alias(t_cookedcmd *cmd, t_shdata *shdata);
void		destroy_alias(t_varkey *alias);

/*
**		BUILTIN : UNALIAS
*/

# define BI_8N	"unalias"
# define BI_8F	builtin_unalias
# define UNALIAS_USAGE	BI_8N": usage: unalias [-a] [name ... ]"

int			builtin_unalias(t_cookedcmd *cmd, t_shdata *shdata);

/*
**		BUILTIN : PWD
*/

# define BI_9N	"pwd"
# define BI_9F	builtin_pwd
# define PWD_USAGE	BI_9N": usage: pwd [-LP]"

int			builtin_pwd(t_cookedcmd *cmd, t_shdata *shdata);

/*
**		BUILTIN : HISTORY
*/

# define BI_10N	"history"
# define BI_10F	builtin_history
# define HIST_USAGE		BI_10N ": usage: " HIST_ALLUSAGE
# define HIST_ALLUSAGE	HIST_USG1 HIST_USG2 HIST_USG3
# define HIST_USG1		"history [-c] [-d offset] [n]"
# define HIST_USG2		" or history -anrw [filename]"
# define HIST_USG3		" or history -ps arg [arg...]"

# define HIST_EARNW		"cannot use more than one of -anrw"
# define HIST_ERANGE	"history position out of range"
# define HIST_ECNFLCT	"conflicting with option -"

int			builtin_history(t_cookedcmd *cmd, t_shdata *shdata);
int			flag2index(int flag);
int			hist_optaction(t_optdata *opt_data, t_checkopt_inf *info);
int			print_ehistoor(int pos);
int			hist_no(char *param, t_shdata *shdata);
int			hist_c(char *param, t_shdata *shdata);
int			hist_d(char *param, t_shdata *shdata);
int			hist_a(char *param, t_shdata *shdata);
int			hist_s(int optret, t_cookedcmd *cmd, t_shdata *shdata);
int			hist_p(int optret, t_cookedcmd *cmd, t_shdata *shdata);
int			hist_w(char *param, t_shdata *shdata);
int			hist_r(char *param, t_shdata *shdata);
int			hist_n(char *param, t_shdata *shdata);
t_histentry	*convert_file2entries(t_histentry *head, char *file, \
									int *entry_count);
t_histentry	*convert_file2entries_nd(t_histentry *head, char *file, \
									int *entry_count, t_histbook *from);

/*
**		BUILTIN : SET
*/

# define BI_11N	"set"
# define BI_11F	builtin_set
# define SET_USAGE	SET_USGP1 SET_USGP2 SET_USGP3 SET_USGP4
# define SET_USGP1	SET_USG_L1 SET_USG_L2 SET_USG_L3 SET_USG_L4 SET_USG_L5
# define SET_USGP2	SET_USG_L6 SET_USG_L7 SET_USG_L8 SET_USG_L9 SET_USG_L10
# define SET_USGP3	SET_USG_L11 SET_USG_L12 SET_USG_L13 SET_USG_L14 SET_USG_L15
# define SET_USGP4	SET_USG_L16 SET_USG_L17
# define SET_USG_L1	BI_11N": usage: set [[-|+]eHP] [[-|+]o option-name]\n"
# define SET_USG_L2	" Options:\n"
# define SET_USG_L3	"  -e  Exit immediately if a command exits with a \n"
# define SET_USG_L4	"      non-zero status\n"
# define SET_USG_L5	"  -H  Enable ! style history substitution.  This flag\n"
# define SET_USG_L6	"      is on by default when the shell is interactive.\n"
# define SET_USG_L7	"  -P  If set, do not follow symbolic links when\n"
# define SET_USG_L8	"      executing commands such as cd which change the\n"
# define SET_USG_L9	"      current directory.\n"
# define SET_USG_L10 "  -o option-name\n"
# define SET_USG_L11 "      Set the variable corresponding to option-name:\n"
# define SET_USG_L12 "        emacs         use an emacs-style line editing\n"
# define SET_USG_L13 "                      interface\n"
# define SET_USG_L14 "        errexit       same as -e\n"
# define SET_USG_L15 "        histexpand    same as -H\n"
# define SET_USG_L16 "        history       enable command history\n"
# define SET_USG_L17 "        syntax-color  enable syntax color"

int			builtin_set(t_cookedcmd *cmd, t_shdata *shdata);
int			set_optaction(t_optdata *opt_data, t_checkopt_inf *info);

# define BI_12N	"snake"
# define BI_12F	builtin_snake

int			builtin_snake(t_cookedcmd *cmd, t_shdata *shdata);

/*
**		BUILTIN - REPACK
*/

# define BUILTINS_COUNT		12
# define BUILTINS_NAME	BINS_N1, BINS_N2
# define BUILTINS_F		BINS_F1, BINS_F2
# define BINS_N1	BI_1N, BI_2N, BI_3N, BI_4N, BI_5N, BI_6N, BI_7N, BI_8N
# define BINS_F1	BI_1F, BI_2F, BI_3F, BI_4F, BI_5F, BI_6F, BI_7F, BI_8F
# define BINS_N2	BI_9N, BI_10N, BI_11N, BI_12N
# define BINS_F2	BI_9F, BI_10F, BI_11F, BI_12F

void		print_bad_opt(char *progname, int opt);
int			print_eargreq(char *head, char *usage, int opt);
int			usage_error(char *usage);

#endif
