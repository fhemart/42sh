/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:47:20 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/09 20:23:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLETE_H
# define AUTOCOMPLETE_H

# include "ftsh.h"

typedef struct s_books	t_books;
typedef struct s_shinfo	t_shinfo;

typedef struct		s_tab
{
	t_shinfo		*shinfo;
	int				status;
	int				quoted;
	int				quotedmode;
	int				count_backtick;
	int				begin;
	int				current;
	t_chrmsk		chrmsk;
	t_cell			*curs;
	char			path[PATH_MAX];
	int				bi;
	int				writed;
	int				tabwrited;
}					t_tab;

enum				e_pageprint
{
	PP_COL = 0,
	PP_LI,
	PP_LIMIT
};

# define TAB_QUO 	"\"'"

# define TAB_INDQUO	"\""

# define FNTAB_STR 	"\"'\\;|&(` "

# define FNT1 		tab_quote
# define FNT2 		tab_quote
# define FNT3 		tab_backslash
# define FNT4 		tab_semico
# define FNT5		tab_semico
# define FNT6 		tab_epersand
# define FNT7 		tab_semico
# define FNT8 		tab_backtick
# define FNT9 		tab_space

# define FNT_COUNT	9
# define FNT_ALL	FNT1, FNT2, FNT3, FNT4, FNT5, FNT6, FNT7, FNT8, FNT9

int					tab_space(t_tab *state, t_term *term);
int					tab_load(t_tab *state, t_term *term);
int					tab_quote(t_tab *state, t_term *term);
int					tab_backslash(t_tab *state, t_term *term);
int					tab_semico(t_tab *state, t_term *term);
int					tab_epersand(t_tab *state, t_term *term);
int					tab_backtick(t_tab *state, t_term *term);
int					tab_load(t_tab *state, t_term *term);
int					tab_request(char *word, t_tab *state, t_term *term);
int					tab_next(t_prompt *prompt, t_term *term, t_tab *state);
void				tab_get_regular_binary(t_books *books, char *word, \
											t_tab *state);
int					tab_get_unknow(t_books *books, char *word, t_tab *state, \
										t_term *term);
int					tab_ifdir(t_tab *state, t_term *term, char *word, int bs);
int					isdir(const char *path);
int					tab_ifexecbin(t_tab *state, char *word);
int					tab_anal(t_prompt *prompt, t_term *term, char c, \
											t_tab *state);
void				erase_word(t_books *books, t_term *term, t_tab *state, \
							int index);
t_word				*get_next_word(t_word *word, t_dict_result *result);
int					tab_writeresult(t_books *books, t_term *term, \
								t_dict_result *result);
int					tabtab_isvalide(t_prompt *prompt, t_tab *state);
int					tabtab(t_books *books, t_tab *state, t_term *term);
int					print_result(t_term *term, t_word *word, t_tab *state, \
								t_dict_result *result);
int					print_result_page(t_word *elem, int col, t_term *term, \
										t_books *books);
int					get_pageprint(t_term *term, t_books *books, int *pp);
int					load_resultinfo(t_books *books, t_dict_result *result);
int					print_word(t_word *elem, t_books *books);
t_bool				is_dictionary_result(t_books *books);
int					tab_fptr_addbin(char *detail, char *word, \
									t_dictionary *dictionary);
void				tab_browse_unknow(char *cooked_path, t_tab *state, \
									t_dictionary **dictionary);
#endif
