/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:45:27 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/05 08:03:06 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

t_term							*ft_term_init(char *term_name)
{
	t_term						*new_term;

	if (!(new_term = malloc(sizeof(t_term))))
		return (NULL);
	ft_bzero(new_term, sizeof(t_term));
	ft_term_sigwinch(new_term, 0);
	tcgetattr(0, &new_term->backup);
	tcgetattr(0, &new_term->current);
	tgetent(NULL, term_name);
	new_term->mode = 1;
	new_term->scrollcurs = -1;
	new_term->trunckmove = 0;
	return (new_term);
}
