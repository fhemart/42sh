/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:42:25 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/24 14:54:37 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H
# include <curses.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <stdio.h>
# include "libft.h"
# include "ft_lstr.h"
# include "ft_pool.h"
# include "ft_dlist.h"
# include "ft_prompt.h"
# include "ft_curs.h"
# include "ft_controls.h"

# define TC_DEBUG		0

# define DEF_TERMSELECT		DEF_TERMSELECT1 DEF_TERMSELECT2
# define DEF_TERMSELECT1	"Could not load termios database:"
# define DEF_TERMSELECT2	" Default terminal selected\n"

# define RESIZE_SMOOTH		1
# define TC_CLEAR			"cl"
# define TC_DEL				"dc"
# define TC_DELTOEND		"cd"
# define TC_DELTOENDL		"ce"
# define TC_LEFT			"le"
# define TC_RIGHT			"nd"
# define TC_SCROLLDO		"sf"
# define TC_SCROLLUP		"sr"
# define TC_CARRET			"cr"
# define TC_INTE			"te"
# define TC_INTI			"ti"
# define TC_REVERSEVID		"mr"
# define TC_RESETVID		"me"

typedef struct s_con	t_con;
struct					s_con
{
	int					co;
	int					li;
	int					size;
	int					lastco;
	int					lastli;
};

typedef struct			s_term
{
	struct termios		current;
	struct termios		backup;
	struct s_prompt		*prompt;
	t_con				*con;
	int					mode;
	int					scrollcurs;
	int					nbcharwrite;
	int					trunckmove;
	int					trunckli;
	int					cc;
	int					enterhit;
	long				lastkey;
	char				toosmall;
}						t_term;

t_term					*ft_term_init(char *term_name);
void					ft_term_restore(t_term *term);
void					ft_term_setcanon(t_term *term);
long					ft_term_readkey(void);
int						ft_term_ifhandler(long key, t_term *term);
void					ft_term_close(t_term *term);
void					ft_term_debug_putfd(char *str);
void					ft_term_sighandler(int sig);
t_con					*ft_term_getsize(int action);
t_con					*ft_term_sigwinch(t_term *term, int mode);
void					ft_term_update_size(t_con *con, struct winsize *ws);
int						ft_term_writetc(char *cap);
int						ft_term_get_curse_pos(t_term *term);
#endif
