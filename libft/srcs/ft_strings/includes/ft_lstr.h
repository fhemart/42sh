/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 04:48:41 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:45:17 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTR_H
# define FT_LSTR_H

# include <unistd.h>
# include "libft.h"

typedef struct s_lstr	t_lstr;

struct	s_lstr
{
	t_lstr		*next;
	int			type;
	size_t		totalsize;
	size_t		len;
	char		buffer[0];
};

t_lstr	*ft_lstrnew_empty(size_t size);

t_lstr	*ft__strnew(const char *str);
t_lstr	*ft__strnnew(const char *str, size_t n);
t_lstr	*ft_nstrnew(const char *src, size_t n);

t_lstr	*ft__strcat(t_lstr **dst, const char *src);
t_lstr	*ft__strncat(t_lstr **dst, const char *src, size_t n);
t_lstr	*ft_nstrcat(t_lstr **dst, const char *src);
t_lstr	*ft_nstrncat(t_lstr **dst, const char *src, size_t n);

char	*ft_lstr_tostring(t_lstr *str);

int		ft_putlstr(t_lstr *str);
int		ft_putlstr_fd(t_lstr *str, int fd);

int		ft_putlstrendl(t_lstr *str);
int		ft_putlstrendl_fd(t_lstr *str, int fd);

void	ft_lstrclr(t_lstr *str);
void	ft_lstrdel(t_lstr **str);
void	ft_lstrdelone(t_lstr **str);

size_t	ft_lstrlen(t_lstr *str);

#endif
