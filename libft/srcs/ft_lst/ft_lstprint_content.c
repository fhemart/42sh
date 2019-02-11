/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 00:19:39 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/25 00:23:30 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void			ft_lstprint_content(t_list *lst)
{
	write(1, (char*)lst->content, lst->content_size);
}
