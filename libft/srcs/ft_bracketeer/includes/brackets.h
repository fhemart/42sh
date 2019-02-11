/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:44:51 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:44:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_H
# define BRACKETS_H

# include "libft.h"
# include "ft_stack.h"

# define BRACK_DEBUGPRINT		0
# define MIN_BRSTACK_HEIGHT		8

# define BRACK_OPEN			0
# define BRACK_CLOSE		1

typedef struct s_escinfo	t_escinfo;
typedef struct s_brinfo		t_brinfo;
typedef struct s_brfeed		t_brfeed;
typedef struct s_brdata		t_brdata;
typedef struct s_brset		t_brset;
typedef struct s_escset		t_escset;
typedef struct s_br_return	t_br_return;

enum		e_brtype
{
	BR_QUOTE = 0,
	BR_ESCAPE = 1
};

enum		e_brstatus
{
	BR_ABORTED = -1,
	BR_INCOMPLETE = 0,
	BR_SUCCESS = 1
};

struct		s_br_return
{
	enum e_brstatus	status;
	char			*parsed_src;
	size_t			parsed_size;
	t_stack			*opened_quotes;
};

struct		s_escinfo
{
	int			index;
	int			type;
	char		*escape;
	int			size;
};

struct		s_brinfo
{
	int			index;
	int			type;
	char		*op;
	int			size[2];
	char		*cl;
	t_chrmsk	expmatch;
};

struct		s_escset
{
	t_brset		*next;
	t_escinfo	info;
};

struct		s_brset
{
	t_brset		*next;
	t_brinfo	info;
};

struct		s_brfeed
{
	char		*(*error_lift)(t_br_return*, void*);
	void		*param;
};

struct		s_brdata
{
	t_stack		*brstack;
	t_chrmsk	start_occ;
	t_brset		*sets;
	char		*src;
	t_brfeed	*feeder;
	t_bool		isset;
};

t_brdata	*create_new_brdata(char **ocm, size_t setscount, t_bool bs_escape);

t_brdata	*new_brdata(t_bool addbsescape);
void		brdata_updatesrc(t_brdata *data, char *src);
void		brdata_resetsrc(t_brdata *data, char *src);

int			brdata_addfeeder(char *(*error_lift)(t_br_return*, void*), \
								void *param, t_brdata *data);
int			brdata_updatefeeder(char *(*error_lift)(t_br_return*, void*), \
								void *param, t_brdata *data);

void		brdata_del(t_brdata **brdata);

t_bool		is_openbr(t_brdata *data, char *index);
t_bool		check_brackets(t_brdata *data);

t_br_return	*get_next_qword(t_brdata *data);
size_t		get_qword_size(t_brdata *data, t_chrmsk *occ, char *start);
char		*get_next_closure(t_brdata *data, char *opened_quote);
void		destroy_br_return(t_br_return **br_ret, t_bool keep_parsed);

#endif
