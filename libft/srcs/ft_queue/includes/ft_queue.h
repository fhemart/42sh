/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:10:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:46:39 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include "libft.h"

typedef struct s_queue	t_queue;

struct		s_queue
{
	void	**stock;
	int		scapacity;
	int		samount;
	int		front;
	int		back;
};

t_queue		*ft_queue_new(int stock_capacity);
void		ft_queue_clear(t_queue *queue);
void		ft_queue_destroy(t_queue **queue);
void		ft_queue_clean_content(t_queue *queue, void (*clean)(void*));
void		ft_queue_clean_destroy(t_queue **queue, void (*clean)(void*));

int			ft_queue_add(t_queue *queue, void *toadd);
int			ft_queue_addfront(t_queue *queue, void *toadd);
void		*ft_queue_get(t_queue *queue);
void		*ft_queue_getback(t_queue *queue);
void		*ft_queue_lookfront(t_queue *queue);
void		*ft_queue_lookback(t_queue *queue);
void		*ft_queue_lookat(t_queue *queue, int at);
int			ft_queue_replaceat(t_queue *queue, void *rep, int at);

t_bool		ft_queue_isempty(t_queue *queue);
int			ft_queue_get_height(t_queue *queue);

t_bool		ft_queue_isfull(t_queue *queue);
int			ft_queue_extend(t_queue *queue);

#endif
