/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zebu_core.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:27:37 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/16 19:38:48 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ZEBU_CORE_H
# define FT_ZEBU_CORE_H

# include "ft_tlex.h"
# include "ft_pool.h"

/*
**	INITIALIZATION
*/

void			factory_init(t_tkn_factory *factory, t_tlexicon *tlex, \
							void *customparam);

int				factory_get_stacks(t_tkn_factory *factory);
t_stack			*get_expr_stack(int gsd);
t_stack			*get_token_stack(int gsd);
int				factory_init_pools();
t_pool			*get_exptoken_pool(int gsd);
t_pool			*get_token_pool(int gsd);

/*
**	ANALYZING
*/

void			factory_analyze(t_tkn_factory *factory);
void			factory_ending(t_tkn_factory *factory);

int				check_state(t_tkn_factory *factory);
int				check_substate(t_tkn_factory *factory);
void			shift(t_tkn_factory *factory);
void			reduce(t_tkn_factory *factory);

/*
**	CLOSURE
*/

void			factory_close(t_tkn_factory *factory, t_tfreturn *ret);

/*
**	BLACKLIST TOOLS
*/

void			add_expr_to_blacklist(t_blacklist *blacklist, int expr);
t_bool			expr_is_blacklisted(t_blacklist *blacklist, int expr);
void			reset_blacklist(t_blacklist *blacklist);

/*
**	EXPR TOOLS
*/

void			discard_expr(t_stack *expressions, t_tkn_factory *factory);
t_exptoken		*exptoken_freshdup(t_exptoken *src);
t_tkn_expr		*get_expmodel(t_tkn_grammar *grammar, int expid);
t_bool			id_isexpr(int id);
t_exptoken		*new_exptoken(int id, t_tkn_expr *model);

/*
**	OTHER TOOLS
*/

t_token			*take_next_token(t_tkn_factory *factory);
int				close_state(t_tkn_factory *factory, t_exptoken *expr);
void			factory_set_error_msg(t_tkn_factory *factory);
int				fill_container(t_tkn_factory *factory);
t_bool			try_expanding(t_tkn_factory *factory, t_exptoken *expr, int id);

/*
**	*******************************************
*/

# define TLEXICON_STACK_HEIGHT	16

# define TF_UNVALIDSTATE		-1
# define TF_CHECKSTATE			0
# define TF_LASTSTATE			0
# define TF_ENDSTATES			0
# define TF_LEXEND				0
# define TF_SHIFT				0
# define TF_CONTINUE			1

# define TOKEN_FACTORY_START	TF_STATUS_ANALYZING

# define TFACTORY_ERR_EOF		"syntax error: unexpected end of file"
# define TFACTORY_ERR_UET		"syntax error near unexpected token `"

#endif
