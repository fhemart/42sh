/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 02:00:19 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 07:51:43 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H
# include "ftsh.h"
# define MRIGHT 1130044187
# define MLEFT 1146821403
# define MUP 1096489755
# define MDOWN 1113266971
# define THOME 4741915
# define TEND 4610843
# define MTC 42947
# define MTV 10127586
# define MTX 8948194
# define ENTER 13
# define CTRL_D 4
# define UP 4283163
# define LEFT 4479771
# define RIGHT 4414235
# define DOWN 4348699
# define DELETTE 127
# define WORDFW 26139
# define WORDBA 25115
# define ELEFT 2
# define ERIGHT 6
# define LIUP 16
# define LIDO 14
# define END 5
# define BEG 1
# define CPY 17179
# define PASTE 22043
# define CUT 22555
# define MODE0 12315
# define EPASTE 25
# define SUPCPY 11
# define TAB 9
# define CTRL_C 3
# define CLEAR 12
# define BSEARCH 18
# define CTRL_G 7
# define EUP 28699
# define EDOWN 28187

# define NBKEYS_STD 21
# define KEYS_STD_1 ENTER, UP, LEFT, RIGHT, DOWN, CTRL_D, DELETTE, MRIGHT
# define KEYS_STD_2 MLEFT, MUP, MDOWN, TEND, THOME, MTC, MTV, MTX, TAB, CTRL_C
# define KEYS_STD_3 CLEAR, BSEARCH, CTRL_G
# define KEYS_STD KEYS_STD_1, KEYS_STD_2, KEYS_STD_3

# define NBKEYS_EMACS 25
# define KEYS_EMACS_1 ENTER, UP, LEFT, RIGHT, DOWN, CTRL_D, DELETTE, WORDFW
# define KEYS_EMACS_2 WORDBA, ELEFT, ERIGHT, LIUP, LIDO, END, BEG
# define KEYS_EMACS_3 MODE0, EPASTE, SUPCPY, TAB, CTRL_C, CLEAR, BSEARCH
# define KEYS_EMACS_4 CTRL_G, EUP, EDOWN
# define KEYS_EMACS KEYS_EMACS_1, KEYS_EMACS_2, KEYS_EMACS_3, KEYS_EMACS_4

# define FENTER ft_control_enter
# define FUP ft_control_hystoryup
# define FLEFT ft_control_left
# define FRIGHT ft_control_right
# define FDOWN ft_control_hystorydo
# define FCTRL_D ft_control_exit
# define FDELETTE ft_control_delette
# define FWORDFW ft_control_movewordfw
# define FWORDBA ft_control_movewordba
# define FLIUP ft_control_moveliup
# define FLIDO ft_control_movelido
# define FBEG ft_control_movebeg
# define FEND ft_control_moveend
# define FCPY ft_control_cpy
# define FPASTE ft_control_paste
# define FMODE0 ft_control_nothing
# define FSUPCPY ft_control_supcpy
# define FTAB control_tab
# define FCTRLC ft_control_ctrlc
# define FCLEAR ft_control_clear
# define FCTRLG ft_control_ctrlg
# define FBSEARCH ft_control_bsearch

# define FN_EMACS_1 FENTER, FUP, FLEFT, FRIGHT, FDOWN, FCTRL_D, FDELETTE
# define FN_EMACS_2 FWORDFW, FWORDBA, FLEFT, FRIGHT, FLIUP, FLIDO, FEND
# define FN_EMACS_3 FBEG, FMODE0, FPASTE, FSUPCPY, FTAB
# define FN_EMACS_4 FCTRLC, FCLEAR, FBSEARCH, FCTRLG, FUP, FDOWN
# define FN_EMACS FN_EMACS_1, FN_EMACS_2, FN_EMACS_3, FN_EMACS_4

# define FN_STD_1 FENTER, FUP, FLEFT, FRIGHT, FDOWN, FCTRL_D, FDELETTE, FWORDFW
# define FN_STD_2 FWORDBA, FLIUP, FLIDO, FEND, FBEG, FCPY, FPASTE, FSUPCPY, FTAB
# define FN_STD_3 FCTRLC, FCLEAR, FBSEARCH, FCTRLG
# define FN_STD FN_STD_1, FN_STD_2, FN_STD_3

# define BSALLOWED_CNT	11
# define BSALLOWED		BSALLOWED1, BSALLOWED2
# define BSALLOWED1		CTRL_G, BSEARCH, CLEAR, CTRL_C, CTRL_D, LEFT
# define BSALLOWED2		RIGHT, DELETTE, UP, DOWN, ENTER

typedef struct s_control	t_control;

t_control			*get_std_controls(void);
t_control			*get_emacs_controls(void);
int					control_tab(t_prompt *prompt, t_term *term);
int					ft_control_enter(t_prompt *prompt, t_term *term);
#endif
