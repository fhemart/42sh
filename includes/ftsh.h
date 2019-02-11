/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:20:05 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/07 02:44:40 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_H
# define FTSH_H

# include <fcntl.h>
# include <time.h>
# include "libft.h"
# include "ft_termcap.h"
# include "ft_prompt.h"
# include "ft_dictionary.h"
# include "ft_hashtable.h"
# include "ft_exec.h"
# include "builtins.h"
# include "ft_iuser.h"
# include "books.h"
# include "autocomplete.h"
# include "controls.h"
# include "errormsg.h"

# define SHELL_NAME		"42sh"
# define CMD_SUBST_STR	"command substitution"

extern int	g_last_signal;
void		pipe_sig(int sig);

typedef struct s_builtin	t_builtin;
typedef struct s_shdata		t_shdata;
typedef struct s_shinfo		t_shinfo;
typedef struct s_shhist		t_shhist;
typedef struct s_histentry	t_histentry;
typedef struct s_histbook	t_histbook;

struct		s_builtin
{
	char	*name;
	int		(*f)(t_cookedcmd*, t_shdata*);
};

struct		s_shinfo
{
	t_list	*path;
	t_list	*cdpath;
	char	*pwd;
	char	*home;
};

# define DEFAULT_HISTFILE	".42sh_history"
# define DEFAULT_HISTSIZE	500
# define HC_IGNDUPS		0b1
# define HC_IGNSPACE	0b10
# define HC_IGNBOTH		0b11

struct		s_histentry
{
	t_histentry		*next;
	t_histentry		*prev;
	char			*string;
	char			*modified;
	t_bool			saved;
	time_t			timestamp;
};

void		hist_clean_modified(t_histbook *history);
int			hist_update_entry(t_histentry *entry, char *new_string);
int			hist_save_modified(t_histbook *history, t_histentry *tosave);
int			hist_save_line2modified(t_histbook *history, char *line);

struct		s_histbook
{
	t_histbook	*next;
	char		*filename;
	int			line_read;
};

struct		s_shhist
{
	t_histentry		*entries;
	t_histentry		*current_histline;
	t_histentry		*last_bsentry;
	t_histbook		*files;
	int				entry_count;
};

typedef struct s_emarkmod	t_emarkmod;
typedef struct s_histemark	t_histemark;

typedef enum e_em_modt		t_em_modt;

enum		e_em_modt
{
	MOD_HEAD = (1 << 0),
	MOD_TAIL = (1 << 1),
	MOD_RMSUF = (1 << 2),
	MOD_KPSUF = (1 << 3),
	MOD_PRINT = (1 << 4),
	MOD_QUOTE = (1 << 5),
	MOD_QUSPLIT = (1 << 6),
	MOD_SUBS = (1 << 7),
	MOD_GLWRD = (1 << 8),
	MOD_GLOB = (1 << 9)
};

struct		s_emarkmod
{
	int			state;
	t_em_modt	type;
	char		*search;
	char		*replace;
};

# define HISTEMARKEND_MSK		" \t\n=("
# define HISTEMARK_WEND_MSK		HISTEMARKEND_MSK ":"
# define HISTEMARK_QWEND_MSK	"\n:?"
# define HISTEMARK_MOD_MSK		"htrepqxsGga&"
# define HISTEMARK_MOD_SUBS		7
# define HISTEMARK_MOD_GLOB		8
# define HISTEMARK_MOD_GMAX		10
# define EMARK_WRANGNO			-1
# define EMARK_WRANGLAST		-2
# define EMARK_WRANGSTAR		-3
# define EMARK_WRANGALL			-4
# define EMARK_WRANGLASTSTR		-5

struct		s_histemark
{
	t_chrmsk		endmsk;
	t_emarkmod		modifiers;
	char			**line;
	char			*eventsrc;
	char			*strbegin;
	char			*strend;
	char			*substart;
	char			*replace;
	t_bool			donotexec;
};

int			get_histcontrol(t_shdata *data);
t_histentry	*hist_new_entry(char *str);
char		*hist_get_modified(t_histentry *entry);
void		hist_ins_entry(t_histentry **prev_entry, t_histentry *to_ins);
int			hist_add_entry(t_shhist *history, char *str);
void		hist_print_entry(t_histentry *entry, char *time_format);
t_histentry	*hist_get_nmatch(t_histentry *from, char *nmatch);
t_histentry	*hist_get_strstr(t_histentry *from, char *nmatch);
void		hist_clamp_maxentries(t_shdata *data);
char		*hist_get_nentry(t_shhist *history, int n);
void		hist_del_allentries(t_histentry **from);
void		hist_del_entry(int *entry_count, t_histentry **entry);
int			hist_del_entryat(t_shhist *history, int at);
void		hist_del(t_shhist **history);
t_shhist	*hist_new(char *histfile);
void		hist_print_nentry(t_shhist *hist, int n, char *time_format);
void		hist_print_allentries(t_shhist *hist, char *time_format);
int			hist_append_entries(t_shhist *hist, char *histfile);
int			hist_write_entries(t_shhist *hist, char *histfile);
void		hist_load_entries(t_shhist *hist, char *histfile);
void		hist_load_entries_nd(t_shhist *hist, char *histfile);

t_histbook	*hist_new_book(char *histfile, int line_read);
void		hist_del_book(t_histbook **book);
t_histbook	*hist_find_book(t_histbook *head, char *fname);
void		hist_update_books(t_shhist *hist, char *histfile, int line_read);

int			add_cmd2history(t_shdata *shdata, t_list *line);

# define IS_SUBSHELL	(1 << 0)
# define IS_CMDSUBST	(1 << 1)
# define IS_RDFILE		(1 << 2)
# define PRINT_PS		(1 << 3)

typedef struct s_sub	t_sub;

struct		s_sub
{
	char		*search;
	char		*replace;
};

struct		s_shdata
{
	t_shinfo		info;
	t_shhist		*history;
	t_sh_env		*env;
	t_builtin		*builtins;
	t_queue			*command;
	t_books			*books;
	t_control		*controls;
	t_term			*term;
	char			**argv;
	t_varkey		*aliases;
	char			*emark_laststr;
	char			*emark_lastneedle;
	int				save_stdio[3];
	t_sub			last_sub;
	int				donotexec;
	int				is_fork;
	int				opts;
	int				argc;
	pid_t			pid;
	unsigned char	last_retval;
	int				shell_fd;
};

char		*get_file_content(char *fname);

int			init_shell_history(t_shdata *shdata);
int			init_shell_data(t_shdata *shdata, int ac, char **av, char **env);
int			init_tc_data(t_shdata *ftsh, char **env);
int			init_shell_info(t_shdata *shdata);
void		shdata_destroy(t_shdata *shdata);
void		exit_shell(t_cookedcmd *cmd, t_shdata *shdata, int exit_status);

int			get_ttyline(t_term *term, t_control *controls, char **line, int ps);
int			init_tc(t_term **term, char **env);
int			close_tc(t_term **term);

void		recurs_suppress_modif(t_histentry *n, t_bool next);
void		suppress_ghost_entry(t_histentry **ghost);
void		hist_suppress_modified(t_shhist *hist);

int			save_stdio(int *stdfd);
void		close_saved_stdio(t_shdata *shdata);
int			restore_stdio(int *stdfd);

# define SHELL_RC			"." SHELL_NAME "rc"

int			parse_exec_ret(int value, t_cookedcmd *cmd, pid_t pid);

# define SET_STREMACS	"emacs"
# define SET_EMACS		(1 << 3)
# define SET_FLGEMACS	3
# define SET_STRERREXIT	"errexit"
# define SET_ERREXIT	(1 << 0)
# define SET_STRHISTEXP	"histexpand"
# define SET_HISTEXP	(1 << 1)
# define SET_STRHISTORY	"history"
# define SET_HISTORY	(1 << 4)
# define SET_STRPHSXLNK	"physical"
# define SET_PHSXLNK	(1 << 2)
# define SET_STRSCOLOR	"syntax-color"
# define SET_SCOLOR		(1 << 5)
# define SET_FLGSCOLOR	5
# define SET_MSKSTR		SET_MSKSTR1, SET_MSKSTR2
# define SET_MSKSTR1	SET_STREMACS, SET_STRERREXIT, SET_STRHISTEXP
# define SET_MSKSTR2	SET_STRHISTORY, SET_STRPHSXLNK, SET_STRSCOLOR
# define SET_MSKVALUE	SET_MSKVALUE1, SET_MSKVALUE2
# define SET_MSKVALUE1	SET_EMACS, SET_ERREXIT, SET_HISTEXP, SET_HISTORY
# define SET_MSKVALUE2	SET_PHSXLNK, SET_SCOLOR
# define SET_GNL		(1 << 30)
# define SET_PRINTOPT	(1 << 31)
# define SET_FLGMSK_CNT	6
# define SET_OPT_STR	"eHPo"
# define SET_OPT_OS		1
# define SET_VERBO_CNT	5
# define SET_VERBO_OS	2
# define SET_VSTR1		"errexit", "histexpand", "emacs", "history"
# define SET_VSTR2		"syntax-color"
# define SET_VERBO_STR	SET_VSTR1, SET_VSTR2

int			is_directory(char *dir);
int			is_executable(char *file, t_bool perr, char *errhead, char *cname);

#endif
