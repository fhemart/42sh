/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   books.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 02:34:12 by fhemart           #+#    #+#             */
/*   Updated: 2018/11/09 02:10:37 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOKS_H
# define BOOKS_H

# include "ftsh.h"

typedef struct s_builtin	t_builtin;
typedef struct s_books		t_books;
typedef struct s_tab		t_tab;

struct		s_books
{
	t_dictionary	*bin;
	t_dictionary	*builtins;
	t_dictionary	*onetime;
	t_dictionary	*onetimeall;
	t_dictionary	*all;
	t_dict_result	*result;
	t_hashtable		*hashtable;
	int				allcount;
	int				allmaxlen;
	int				writed;
};

t_books		*new_books(void);
t_books		*gsd_books(int gsd, t_list *binpath, t_builtin *builtins);
int			fill_books(t_books *books, t_list *binpath, t_builtin *builtins);
int			destroy_books(t_books *books);
int			fill_all(t_books *books, t_dictionary *bin, t_dictionary *builtin);
int			fill_onetime_all(t_books *books, t_dictionary *onetime, \
							t_tab *state);
int			to_more(t_books *books, t_tab *state, t_term *term);
int			fill_bin(t_books *books, t_list *binpath);
int			destroy_bin(t_dictionary **bin);
int			parse_htbin(t_hashtable *hashtable, t_list *binpath);
int			parse_bin(t_dictionary *bin, t_hashtable *hashtable, \
					t_list *binpath);
int			fill_builtins(t_books *books, t_builtin *builtins);
int			hashtable_destroy_content(void **content);
void		*hashtable_new_content(char *name, char *fullpath);
int			fill_all_addbin(t_books *books, t_dictionary *dictionary, \
							int i, t_tab *state);
#endif
