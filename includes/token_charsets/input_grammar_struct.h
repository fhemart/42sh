/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_grammar_struct.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:38:06 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:37:49 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_GRAMMAR_STRUCT_H
# define INPUT_GRAMMAR_STRUCT_H

# include "ft_queue.h"
# include "token_charsets/iuser_lexinfo.h"

typedef struct s_io_content		t_iocontent;
typedef struct s_ioredirect		t_ioredirect;
typedef struct s_command		t_command;
typedef struct s_subshell		t_subshell;
typedef struct s_andor			t_andor;
typedef struct s_inputlist		t_inputlist;

struct			s_io_content
{
	t_iocontent	*next;
	char		*str;
	int			type;
	int			ionumber;
};

/*
**	HEREDOCOFFSET is equal to the height of the IO_FILE's rules count.
**	So, if we change the position of IO_FILE (actually IUE_11) we MUST
**	change the value of HEREDOCOFFSET. Else, something dramatic will happens.
*/

# define HEREDOCOFFSET		IUE_11_1
# define NO_IONUMBER		-1

struct			s_ioredirect
{
	t_ioredirect	*next;
	t_iocontent		*iocontent;
	int				ionumber;
};

# define SIMPLE_CMD		0
# define SUBSHELL_CMD	1

struct			s_command
{
	t_command	*next;
	int			type;
	t_iocontent	*iocontent;
	t_queue		*argv;
};

struct			s_subshell
{
	t_subshell	*next;
	int			type;
	t_iocontent	*iocontent;
	t_queue		*ilist;
};

/*
**	and_or type values:
**	0 : the pipeline is preceded by nothing
**	1 : the pipeline is preceded by an AND operator
**	2 : the pipeline is preceded by an OR operator
*/

struct			s_andor
{
	t_command	*pipeline;
	int			type;
	int			retvalue;
};

/*
**	inputlist septype values:
**	0 : default (when a command is separated by semicolumn or by EOL)
*/

struct			s_inputlist
{
	t_queue		*and_or;
	int			septype;
};

t_iocontent		*new_iocontent(char *str, int type);
void			del_iocontent(t_iocontent **iocontent);

t_ioredirect	*new_ioredirect(t_iocontent *iocontent, int ionumber);
void			delone_ioredirect(t_ioredirect **ioredirect);
void			del_ioredirect(t_ioredirect **ioredirect);

t_command		*new_command(void);
void			del_command(t_command **command);

t_subshell		*new_subshell(t_queue *ilist);
void			del_subshell(t_subshell **subshell);

void			del_pipeline(t_command **pipeline);

t_andor			*new_andor(t_command *pipeline, int type);
void			del_andorstruct(t_andor **andor);
void			del_andor(t_queue **andor);

t_inputlist		*new_inputlist(t_queue *andor, int septype);
void			del_inputliststruct(t_inputlist **inputlist);
void			del_inputlist(t_queue **inputlist);

#endif
