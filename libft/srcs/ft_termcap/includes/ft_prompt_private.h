/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 01:21:20 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/15 09:58:50 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_PRIVATE_H
# define FT_PROMPT_PRIVATE_H
# include "ftsh.h"

int				cpy_if_buff_full(int i, char *temp, t_prompt *prompt);
int				tr_lastcol_nolastline(t_line *line, t_term *term);
char			*hist_get_modified(t_histentry *entry);
void			write_hist_res(char *res, t_term *term);
char			*ft_dlist2str(t_line *root);
char			*ft_dlist_clr_dlist2str(t_line *root, t_term *term);
void			ft_dlist_str2dlist(char *src, t_term *term);
int				ft_prompt_clr_exitbs_upd(t_prompt *prompt, t_term *term, \
												t_bool restore);
int				hist_update_curr_histline(t_shhist *hist, char *line, \
												t_bool keep);
int				bsearch_next(t_prompt *prompt, t_term *term);
void			hist_validate_bsearch(t_iuser *iuser);
char			*get_hist_currline_mod(t_iuser *iuser);
t_histentry		*hg_prev_chl(t_shhist *history);
t_histentry		*hg_next_chl(t_shhist *history);
int				hist_update_modified(t_histentry *entry, char *mod, \
										t_bool keep);
t_histentry		*hist_new_empty_entry(t_histentry *prev);
t_histentry		*create_current_histline(t_shhist *hist);
t_histentry		*hist_get_current_histline(t_shhist *hist, t_bool create);
char			*ft_nlst2str(t_list *lst, size_t n);
int				count_previous_bs(char *line, int len);
char			*cancel_cmd(t_prompt *prompt);
t_bool			treat_quotes(t_prompt *prompt);
t_bool			all_quotes_closed(t_prompt *prompt, char *line);
int				if_print_in_nm(t_term *term, t_prompt *prompt);
int				if_print_in_tr(t_term *term);
int				if_wrupdate_in_tr(t_term *term, t_prompt *prompt);
int				if_wrupdate_in_nm(t_term *term, t_prompt *prompt);
int				print_in_bsearch(t_prompt *prompt, t_term *term, \
									char key);
void			write_bsearch(t_term *term, t_prompt *prompt, \
									char *hist_res);
void			putnstr(char *str, int len);
void			repos_cursor(int n);
int				finish_searchfield(t_prompt *prompt, t_term *term);
int				go_newline(t_prompt *prompt, t_term *term);
int				get_scrollcurs(int cursor, t_term *term, \
											t_prompt *prompt, t_con *con);
int				write_ins_truncated(t_line *line, t_term *term);
void			printkey_in_tr(int scrollcurs, int hasauto, \
									t_term *term, t_prompt *prompt);
#endif
