/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:59:15 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 03:29:12 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTROLS_H
# define FT_CONTROLS_H
# include "ft_termcap.h"
# define CPYSIZE 512

typedef struct s_prompt	t_prompt;

int					ft_control_cpy(t_prompt *prompt, t_term *term);
t_lstr				*ft_control_cpyleft(t_prompt *prompt, t_term *term, \
										t_lstr **lstr);
t_lstr				*ft_control_cpyright(t_prompt *prompt, t_term *term, \
										t_lstr **lstr);
int					ft_control_cut(t_prompt *prompt, t_term *term);
int					ft_control_delette(t_prompt *prompt, t_term *term);
int					ft_control_enter(t_prompt *prompt, t_term *term);
int					ft_control_ctrlc(t_prompt *prompt, t_term *term);
int					ft_control_exit(t_prompt *prompt, t_term *term);
int					ft_control_left(t_prompt *prompt, t_term *term);
int					ft_control_movebeg(t_prompt *prompt, t_term *term);
int					ft_control_moveend(t_prompt *prompt, t_term *term);
int					ft_control_movelido(t_prompt *prompt, t_term *term);
int					ft_control_moveliup(t_prompt *prompt, t_term *term);
int					ft_control_movewordba(t_prompt *prompt, t_term *term);
int					ft_control_movewordfw(t_prompt *prompt, t_term *term);
int					ft_control_nothing(t_prompt *prompt, t_term *term);
int					ft_control_paste(t_prompt *prompt, t_term *term);
int					ft_control_pasteleft(t_prompt *prompt);
int					ft_control_pasteright(t_prompt *prompt, t_term *term);
int					ft_control_right(t_prompt *prompt, t_term *term);
int					ft_control_supcpy(t_prompt *prompt, t_term *term);
int					ft_control_clear(t_prompt *prompt, t_term *term);
int					ft_control_hystoryup(t_prompt *prompt, t_term *term);
int					ft_control_hystorydo(t_prompt *prompt, t_term *term);
int					ft_control_bsearch(t_prompt *prompt, t_term *term);
int					ft_control_ctrlg(t_prompt *prompt, t_term *term);
#endif
