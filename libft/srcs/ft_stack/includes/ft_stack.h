/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:22:07 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:44:55 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>
# include "libft.h"

/*
**			FT_STACK : a simple stack auto-growing/resizing.
**						[LIBFT MODULE]
**
**	return values for (int(*function)()) :
**		0 == ERROR
**		1 == OK
**
**	can be checked like 'if (ft_stack_add_content(foo)) then SUCCESS'
**
**	ft_stack_init() MUST be called at first before adding content
**	the t_stack given in parameter need to be allocated by your preference.
*/

# define FT_STACK_SHOW_WARNING	0

# define FT_STACK_ERROR			0
# define FT_STACK_SUCCESS		1
# define FT_STACK_EMPTY			0

# define FT_STACK_HEADER		"<stack>  "
# define FTS_E0	"One or more element requested for cleaning hasn't been found"

# define FT_STACK_NOTEMPTYCLEANER	FT_STACK_HEADER FTS_E0

# define MAX_STACK_BLOCK_SIZE   256
# define INITIAL_STACK_SIZE     10

typedef struct s_stack_block	t_stack_block;
typedef struct s_stack_cleaner	t_stack_cleaner;
typedef struct s_stack			t_stack;

struct			s_stack_block
{
	size_t	size;
	void	**content;
};

struct			s_stack_cleaner
{
	t_stack_cleaner	*next;
	t_stack_cleaner	*previous;
	void			*from;
	void			*to;
	size_t			count;
};

struct			s_stack
{
	t_stack_block	**blocks;
	t_stack_cleaner	*cleaner;
	size_t			blocks_count;
	size_t			max_height;
	size_t			chunk_size;
};

/*
**	PUBLIC FUNCTIONS
*/

int				ft_stack_init(t_stack *stack, size_t chunk_size);
int				ft_stack_add_content(t_stack *stack, void *content);
void			*ft_stack_get_content(t_stack *stack);
int				ft_stack_reset(t_stack *stack);
int				ft_stack_destroy(t_stack *stack);

/*
**	if something has been free'd and need to be rejected from the stack
**	you will need to call cleaneradd.
**	the content address in parameter will be the root of whatever you need to
**	remove, the content_size will be the sizeof(*content), then
**	set the count of contents you need to remove after this address
*/

int				ft_stack_cleaneradd(t_stack *stack, void *content, \
									size_t content_size, size_t count);
void			ft_stack_clean(t_stack *stack);

/*
**	TOOLS FUNCTIONS
*/

void const		*ft_stack_looktop(t_stack *stack);
void const		*ft_stack_lookat(t_stack *stack, int i);
size_t			ft_stack_totalsize(t_stack *stack);
void			ft_stack_replaceat(t_stack *stack, int index, \
									const void *newcontent);
t_bool			ft_stack_isempty(t_stack *stack);

/*
**	CORE FUNCTIONS
*/
t_stack_cleaner	*ft_stack_cleanernew(void *content, \
									size_t content_size, size_t count);
void			ft_stack_cleanerdelfrom(t_stack *stack, t_stack_cleaner *del);
void			ft_stack_cleanerexit(t_stack *stack);
t_bool			ft_stack_removedcheck(t_stack *stack, const void *elem);
int				ft_stack_newblock(t_stack *stack);
int				ft_stack_realloc(t_stack *stack);

#endif
