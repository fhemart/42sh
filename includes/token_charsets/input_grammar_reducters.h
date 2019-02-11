/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_grammar_reducters.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 13:25:42 by jbulant           #+#    #+#             */
/*   Updated: 2018/08/07 10:39:01 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_GRAMMAR_REDUCTERS_H
# define INPUT_GRAMMAR_REDUCTERS_H

typedef struct s_tkn_factory	t_tkn_factory;
typedef struct s_exptoken		t_exptoken;

void	clean_expr_overage(t_tkn_factory *factory, t_exptoken *expr);

void	*reduce_simple_command(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_cmd_name(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_cmd_suffix(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_separator_op(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_separator(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_command(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_complete_command(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_list(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_and_or(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_io_redirect(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_io_file(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_filename(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_io_here(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_here_end(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_pipeline(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_cmd_prefix(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_cmd_word(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_linebreak(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_newline_list(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_compound_command(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_subshell(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_compound_list(t_tkn_factory *tfactory, t_exptoken *expr);
void	*reduce_rdlist(t_tkn_factory *factory, t_exptoken *expr);

#endif
