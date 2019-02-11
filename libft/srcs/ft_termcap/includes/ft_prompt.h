/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 23:29:01 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/02 18:47:13 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_H
# define FT_PROMPT_H

# include "ft_termcap.h"

# define MODE_NORMAL	1
# define MODE_TRUNC		2
# define SECU_OFFSET	4
# define PROMPT_DEBUG	0

typedef struct s_con		t_con;
typedef struct s_term		t_term;
typedef struct s_line		t_line;
typedef struct s_control	t_control;
typedef struct s_prompt		t_prompt;
typedef struct s_cell		t_cell;

struct				s_cell
{
	t_cell			*next;
	t_cell			*prev;
	char			c;
	char			skip;
	int				co;
	int				li;
};

struct				s_prompt
{
	char			prompt[FILENAME_MAX];
	char			promptsave[FILENAME_MAX];
	char			*line_save;
	t_stack			brstack;
	int				exit;
	int				done;
	int				hasinsert;
	int				hasdel;
	int				hasauto;
	int				tabstop;
	int				inbsearch;
	int				color;
	int				ps;
	int				promptlen;
	t_pool			*pool;
	t_line			*line;
	char			*cpystr;
	t_list			*str_line;
	int				sline_iter;
	char			*beforetab;
	void			*cparam;
};

struct				s_control
{
	int				nbaction;
	long			*key_handle;
	int				(**f)(t_prompt*, t_term*);
};

t_prompt			*ft_prompt_init(void);
void				ft_prompt_close(t_prompt *prompt);
t_line				*ft_prompt_getline(t_prompt *prompt, t_term *term, \
										t_control *controls);
int					ft_prompt_cleanline(void **content, t_pool *pool, \
						t_line *line);
int					ft_prompt_handlefn(int event, t_prompt *prompt, \
						t_term *term, t_control *controls);
void				ft_prompt_ifresise(t_term *term);
int					ft_prompt_wratcurrent(t_term *prompt);
int					ft_prompt_wrat2(t_term *term, int pos);
int					ft_prompt_cleanscreentr(t_term *term);
int					ft_prompt_cleanscren(t_term *term);
int					ft_prompt_outtrmode(t_term *term, int mode);
int					ft_prompt_returnafterwr(t_term *term);
int					ft_prompt_wrchunck(t_term *term, int start, int size);
void				go_to_endline(t_prompt *prompt, t_term *term, t_line *line);
int					wrupdate_in_nm(t_term *term, t_prompt *prompt);
int					ft_prompt_clean(t_term *term);
int					ft_prompt_wrupdate(t_prompt *prompt, t_term *term);
int					ft_prompt_printable_key(t_prompt *prompt, t_term *term, \
											char key);
int					ft_prompt_fnselector(t_prompt *prompt, t_term *term, \
											long key, t_control *controls);
void				ft_prompt_getline_debug(struct s_line *line, t_term *term);
void				ft_prompt_debug_putfd_current(t_cell *current);
void				ft_prompt_debug_putfd_termsize(t_con *con);
int					ft_prompt_resise(t_term *termptr, int mode, \
										struct winsize *ws);
void				ft_prompt_resize_write(t_term *termptr, t_con *con);
char				*ft_prompt_exportline(t_line *root, t_prompt *prompt);
int					if_print_in_nm(t_term *term, t_prompt *prompt);
int					if_print_in_tr(t_term *term);
int					if_wrupdate_in_tr(t_term *term, t_prompt *prompt);
int					ft_prompt_writechar(t_cell *current, t_term *term, \
											t_prompt *prompt);
void				ft_prompt_exit_bsearch(t_term *term, t_bool restore);
void				resize_smooth(t_term *termptr, struct winsize *ws, \
									char mode);
int					if_min_size(t_term *term);
void				wait_for_min_size(t_term *term, struct winsize *ws);
void				block_input(t_term *term);
#endif
