/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_restore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:40:07 by fhemart           #+#    #+#             */
/*   Updated: 2018/06/03 15:40:40 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

void							ft_term_restore(t_term *term)
{
	signal(SIGWINCH, SIG_DFL);
	tcsetattr(0, TCSADRAIN, &term->backup);
}
