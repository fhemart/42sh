/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_sighandler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:43:45 by fhemart           #+#    #+#             */
/*   Updated: 2018/08/26 13:59:18 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

void		ft_term_sighandler(int sig)
{
	if (sig == SIGWINCH)
		ft_term_sigwinch(NULL, 0);
}
