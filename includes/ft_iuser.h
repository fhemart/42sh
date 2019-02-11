/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iuser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 00:00:17 by jbulant           #+#    #+#             */
/*   Updated: 2018/11/04 17:28:17 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IUSER_H
# define FT_IUSER_H

# define IUSER_DEBUG	0

# include <limits.h>
# include "libft.h"
# include "ft_strings.h"
# include "ft_tlex.h"
# include "token_charsets/iuser_lexinfo.h"
# include "brackets.h"
# include "brackets_shellinfo.h"
# include "ft_termcap.h"

# define IUSER_MAX_IOFD		8192

typedef struct s_iuser		t_iuser;
typedef struct s_shdata		t_shdata;
typedef struct s_histemark	t_histemark;
typedef struct s_emarkmod	t_emarkmod;

struct		s_iuser
{
	t_tlexicon		*tlex;
	t_tkn_grammar	*grammar;
	t_brdata		*brdata;
	t_shdata		*shdata;
	t_queue			*op_expr;
	t_pool			*int_pool;
	char			*src;
	char			*ps1;
	int				(*start_input)(t_iuser*, char*);
};

t_iuser		*new_iuser(char *ps1, t_shdata *shdata);
void		iuser_del(t_iuser **iuser);
void		clean_input(void);

t_tlexicon	*get_iuser_tlex(t_iuser *iuser, int gsd);
t_brdata	*get_sh_brdata(t_iuser *iuser, int gsd);
char		**get_iuser_expr_str(void);
char		**get_sh_brinf(void);

int			get_inputline(t_term *term, t_shdata *data, char **line, int ps);
int			gnl_mode(t_term *term, t_shdata *data, char **line, int ps);
int			get_histexpand(t_shdata *data, t_prompt *prompt, char **line);

void		remove_opexpr(t_iuser *iuser);

int			display_ps1(t_iuser *iuser, char *ps1);
t_bool		iuser_refill_src_ps2(t_iuser *iuser, int last_type);
char		*br_display_ps2(t_br_return *data, t_iuser *iuser);

t_tlexicon	*get_hist_tlex(int gsd);

int			p_eeventnf(t_histemark *hem);
int			p_emodnf(char mod);
int			p_ebwspec(t_histemark *hem);
int			p_emsubfail(t_histemark *hem);
int			p_enopsub(void);

int			get_event(t_histemark *hem, char *emarkstr, t_shdata *data);
int			get_event_word(t_histemark *hem, t_shdata *data, t_chrmsk wendmsk);
int			get_words_replace(int wrange[2], t_histemark *hem);
char		*wordq_replace(int wrange[2], t_tlexicon *tlex, t_histemark *hem);
int			get_word_laststr(t_histemark *hem, t_shdata *data);
int			get_words(t_histemark *hem, t_shdata *data);

int			get_next_modtype(t_histemark *hem, t_emarkmod *mod, \
							t_chrmsk *modmsk, t_shdata *data);

int			update_line(t_histemark *hem, t_prompt *prpt, char **line, \
						t_shdata *data);

int			get_modifiers(t_histemark *hem, t_emarkmod *mods, t_shdata *data);
int			pmods_gw(char *str, t_histemark *hem, t_lstr *lstr, t_emarkmod *md);
int			pmods(t_histemark *hem, t_emarkmod *mods);
int			pmodx(t_histemark *hem);
int			pmodq(t_histemark *hem);
int			pmodp(t_histemark *hem);
int			pmodh(t_histemark *hem);
int			pmodt(t_histemark *hem);
int			pmodr(t_histemark *hem);
int			pmode(t_histemark *hem);

int			print_and_save_line(t_shdata *data, char **line, int ps);

#endif
