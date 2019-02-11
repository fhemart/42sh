/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:13:04 by fhemart           #+#    #+#             */
/*   Updated: 2018/09/06 04:45:00 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CURS_H
# define FT_CURS_H
# include "ft_termcap.h"
# define CURSMOVE_MANUAL	1
# define CURSMOVE_AUTO		2

int			ft_curs_movco(int origin, int newco, t_term *term);
int			ft_curs_movli_up(int origin, int newli, t_term *term);
int			ft_curs_movli_do(int origin, int newli, t_term *term);
int			ft_curs_movli(t_term *term, int currentli, int newli);
int			ft_curs_mov(t_term *term, int newpos);
int			ft_curs_movco_le(int origin, int newco, t_term *term);
int			ft_curs_trunckmove(t_term *term, int newpos);
int			ft_curs_trunckmovele(t_term *term, int newpos);
int			ft_curs_trunckmoveri(t_term *term, int newpos);
#endif
