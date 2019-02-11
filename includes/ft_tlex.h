/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 04:05:20 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:40:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TLEX_H
# define FT_TLEX_H

# include "ft_tkn_type.h"
# include "libft.h"
# include "ft_strings.h"
# include "ft_pool.h"
# include "ft_stack.h"
# include "ft_queue.h"
# include "brackets.h"

typedef struct s_token			t_token;
typedef struct s_exptoken		t_exptoken;
typedef struct s_grammar_state	t_grammar_state;
typedef struct s_tkn_factory	t_tkn_factory;
typedef struct s_tlexfeed		t_tlexfeed;
typedef struct s_wordpolish		t_wordpolish;
typedef struct s_tlexicon		t_tlexicon;
typedef struct s_tfreturn		t_tfreturn;

enum		e_fmain_status
{
	TF_STATUS_ANALYZING = 0,
	TF_STATUS_CLOSING = 1,
	TF_STATUS_ERROR = 2,
	TF_STATUS_END = 3
};

struct		s_tlexfeed
{
	char	*(*error_lift)(t_tlexicon*, void*);
	void	*param;
};

struct		s_wordpolish
{
	int		(*action)(t_tlexicon*, t_token*, void*);
	void	*param;
};

struct		s_tlexicon
{
	t_tkn_grammar	*grammar;
	t_tlexfeed		*feeder;
	t_wordpolish	*wpolish;
	t_brdata		*quote_data;
	int				main_status;
	t_bool			use_escape;
	t_queue			*tokens;
	char			*src;
	char			*errhead;
};

struct		s_tfreturn
{
	void	*reduced;
	int		final_status;
};

struct		s_tkn_factory
{
	t_tlexicon		*lex;
	t_tkn_grammar	*grammar;
	int				main_status;
	void			*customparam;
	t_token			*tokencontainer;
	t_stack			*expressions;
	t_stack			*tokens;
	t_blacklist		expr_blacklist;
};

t_tfreturn	*ft_zebu_start(t_tlexicon *tlex, char *src, void *customparam);
int			ft_zebu_set_error(t_tkn_factory *factory);
void		token_del(t_token **tok);

void		ft_zebu_exit(void);

/*
**	SUBSTATES TOOLS
*/

int			get_substate_value(t_exptoken *expr);
t_bool		substate_match_id(t_exptoken *expr, int id);
t_bool		substate_match_token(t_exptoken *expr, t_token *tkn);

/*
**	INFO TOOLS
*/

const char	*ft_zebu_get_errmsg(void);
t_bool		ft_zebu_notokleft(t_tkn_factory *factory);

/*
**	OTHER TOOLS
*/

void		*ft_zebu_look_curr_expr(t_tkn_factory *factory);
void		*ft_zebu_get_curr_expr(t_tkn_factory *factory);
void		*ft_zebu_look_curr_tok(t_tkn_factory *factory);
void		*ft_zebu_get_curr_tok(t_tkn_factory *factory);

struct		s_token
{
	int			type;
	char		*content;
	size_t		content_size;
};

struct		s_exptoken
{
	int			id;
	t_bool		isrecursive;
	int			(*rules)[10];
	void		*reduced;
	char		validstate;
	char		maxstate;
	char		tsoffset;
	char		state;
	char		substate;
};

/*
**	TOKEN LEXICON - BASE
*/
t_tlexicon	*ft_tlex_new(char *src, t_bool use_escape, \
						t_tkn_grammar *grammar);
void		ft_tlex_fill(t_tlexicon *tlex);
void		ft_tlex_resetsrc(t_tlexicon *tlex, char *src);
void		ft_tlex_destroy(t_tlexicon **tlex);

/*
**	TOKEN LEXICON - COMPATIBILITY MODE
*/
void		ft_tlex_fill_cmpchk(t_tlexicon *tlex);
t_bool		token_are_compatible(t_token *lh, t_token *rh, t_tkn_template *tpl);
void		look_last_compatibility(t_token *last, t_tlexicon *tlex, \
									t_tkn_template *tpl);
int			get_token_cat(t_token *token, t_tkn_template *templates);

/*
**	TOKEN LEXICON - WORD POLISHER
*/
int			ft_tlex_addwpolish(int (*action)(t_tlexicon*, t_token*, void*), \
							void *param, t_tlexicon *tlex);
int			use_word_polish(t_tlexicon *tlex, t_token *tok, t_wordpolish *wpol);

/*
**	TOKEN LEXICON - SOURCE FEEDER
*/
int			ft_tlex_addfeeder(char *(*error_lift)(t_tlexicon*, void*), \
							void *param, t_tlexicon *tlex);
void		ft_tlex_updatefeeder(char *(*error_lift)(t_tlexicon*, void*), \
								void *param, t_tlexicon *tlex);
int			ft_tlex_feed(t_tlexicon *tlex);

/*
**	TOKEN LEXICON - PRIVATE
*/
void		ft_tlex_errtok(t_tlexicon *tlex);

/*
**	TOKEN LEXICON - WORDS
*/
t_lstr		*get_wordcontent(t_tlexicon *tlex, t_tkn_grammar *grammar);
t_token		*create_word(t_tlexicon *tlex);
t_lstr		*reduce_word(char **src, t_lstr *str, int index);
int			ft_tlex_gword(t_tlexicon *tlex);

/*
**	TOKEN LEXICON - QUOTING
*/
int			extend2qword(t_tlexicon *tlex, t_lstr **str);
void		cancel_qword_creation(t_tlexicon *tlex, t_br_return *br_ret);

/*
**	TOKEN LEXICON - TOKENS
*/
t_token		*create_new_token(const char *src, int size, int type);
t_token		*get_next_token(t_tlexicon *tlex);
int			get_next_token_type(t_tlexicon *tlex, const char *src);
char		*tkn_tostring(t_tkn_grammar *grammar, int value);

#endif
