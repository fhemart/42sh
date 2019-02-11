/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 03:20:57 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 03:30:37 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H
# include "ft_termcap.h"
# define POOL_SIZE		256

typedef struct s_line		t_line;
typedef struct s_cell		t_cell;
typedef struct s_term		t_term;

struct		s_line
{
	t_cell			*head;
	t_cell			*last;
	t_cell			*current;
	int				con_li;
	int				cursor;
	int				lastmove;
	int				nbelem;
	int				*promptlen;
};

t_line		*ft_dlist_createroot(void);
void		ft_dlist_destroyroot(t_line *root);
t_cell		*ft_dlist_createnode(t_pool *pool);
int			ft_dlist_addnode(t_line *root, char c, t_pool *pool);
int			ft_dlist_addlastnode(t_line *root, char c, t_pool *pool);
int			ft_dlist_addfirstnode(t_line *root, char c, t_pool *pool);
int			ft_dlist_addbeforenode(t_cell *cell, char c, t_pool *pool);
int			ft_dlist_addafternode(t_line *root, char c, t_pool *pool);
int			ft_dlist_rmnode(t_line *root, t_pool *pool);
char		*ft_dlist_debug_print(t_line *root);
int			ft_dlist_haswordfw(t_term *term);
int			ft_dlist_haswordba(t_term *term);
int			ft_dlist_rmonenode(t_term *term, t_cell *cell, t_pool *pool);
#endif
