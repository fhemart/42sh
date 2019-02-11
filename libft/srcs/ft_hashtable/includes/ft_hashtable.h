/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:09:43 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 03:24:21 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHTABLE_H
# define FT_HASHTABLE_H
# include "libft.h"
# include <fcntl.h>
# define HASHTABLE_SIZE 256

typedef struct s_hashcontent	t_hashcontent;
struct			s_hashcontent
{
	t_hashcontent	*next;
	size_t			len;
	char			*name;
	char			*fullpath;
};

typedef struct s_hashtable	t_hashtable;
struct			s_hashtable
{
	void			*indexes[HASHTABLE_SIZE];
};

void			ft_hashtable_dbug_printfd(t_hashtable *hashtable);
int				ft_hashtable_destroy(t_hashtable **hashtable, int (*del)());
int				ft_hashtable_new(t_hashtable **hashtable);
int				ft_hashtable_addcontent(char *fullpath, char *name, \
							t_hashtable *hashtable, void *(*new_content)());
void			*ft_hashtable_get(t_hashtable *hashtable, char *tosearch);
#endif
