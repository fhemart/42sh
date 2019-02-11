/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 01:09:50 by fhemart           #+#    #+#             */
/*   Updated: 2018/07/05 12:47:19 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POOL_H
# define FT_POOL_H

# include "libft.h"
# include "ft_stack.h"

# define FT_POOL_SUCCESS	0
# define FT_POOL_ERROR		-1

typedef struct s_pblk	t_pblk;
typedef struct s_pool	t_pool;

struct		s_pblk
{
	t_pblk		*next;
	char		*buff;
	size_t		totalsize;
};

struct		s_pool
{
	t_stack		stack;
	t_pblk		*blocks;
	size_t		blocksize;
	size_t		chunksize;
};

/*
******************************************************************************
**  	 ft_pool_new	* *				MUST BE CALLED AT START				**
******************************************************************************
** 		 (blocksize)	* *		the minimum height of the mempool			**
**  	 (chunksize)	* *		the sizeof the object given for the mempool	**
******************************************************************************
*/

t_pool		*ft_pool_new(size_t blocksize, size_t chunksize);

/*
**	ft_pool_get will return a pointer to an element of size "chunksize",
**	if NULL is returned, then an error has occured during process
*/

void		*ft_pool_get(t_pool *pool);

/*
**	ft_pool_giveback is useful when an element taken via ft_pool_get is not
**	used anymore.
*/

int			ft_pool_giveback(t_pool *pool, void *elem);

/*
**	ft_pool_clean frees the memory overflow caused by a higher request of
**	elements than the original blocksize, then put every pointers
**	left into the pool.
*/

void		ft_pool_clear(t_pool *pool);

/*
**	ft_pool_close frees every blocks inside the memory pool, then frees the
**	pool itself.
*/

void		ft_pool_close(t_pool **pool);

/*
**	these functions are there to ensure the proper functioning of the pool
*/

t_pblk		*ft_pool_new_block(size_t totalsize);
void		ft_pool_close_block(t_pblk *block);

int			ft_pool_fill(t_stack *stack, t_pblk *block, size_t size);
int			ft_pool_refill(t_stack *stack, t_pblk *block, size_t size);

/*
******************************************************************************
** 	   allocating functions 		*				frequency				**
******************************************************************************
**		   ft_pool_new 				*				always					**
**		   ft_pool_get 				*		  when pool is empty			**
**		 ft_pool_giveback			*		  when stack is full			**
******************************************************************************
*/

#endif
