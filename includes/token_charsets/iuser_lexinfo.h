/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iuser_lexinfo.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:10:51 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/12 02:52:35 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IUSER_LEXINFO_H
# define IUSER_LEXINFO_H

# include "ft_tlex.h"
# include "token_charsets/input_tkn_chrset.h"
# include "token_charsets/input_tkn_grammar.h"
# include "token_charsets/iuser_tkn_chrmsk.h"

t_tkn_template	*get_iuser_tokens(void);
t_tkn_expr		*get_iuser_expressions(void);
char			*get_token_strvalue(int value);
t_tkn_grammar	*get_iuser_grammar(int gsd);

#endif
