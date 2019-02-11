/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrprivate.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 04:59:02 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:45:55 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTRPRIVATE_H
# define FT_LSTRPRIVATE_H

typedef enum e_lstrtype	t_lstrtype;
typedef struct s_lstr	t_lstr;

enum	e_lstrtype
{
	T_LSTR = 0,
	T__STR = 1,
	T_NSTR = 2
};

size_t	ft_lstrfreespace(t_lstr *str);

t_lstr	*ft_lstrnew_empty(size_t size);

void	ft_lstradd(t_lstr **str, t_lstr *newstr);

#endif
